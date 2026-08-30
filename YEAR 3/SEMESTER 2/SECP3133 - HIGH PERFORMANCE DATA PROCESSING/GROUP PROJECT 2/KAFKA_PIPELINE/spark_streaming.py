"""
spark_streaming.py
=======================
PySpark Structured Streaming consumer.
Reads from Kafka → Converts micro-batch to Pandas → CNN inference → writes to Elasticsearch.
"""

import os
import sys

# Limit TensorFlow memory spam
os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"

# 1. Force Spark to bind to localhost
os.environ["SPARK_LOCAL_IP"] = "127.0.0.1"

# 2. Tell Spark where Hadoop is AND add it to the Windows PATH so the DLL loads
os.environ["HADOOP_HOME"] = "C:\\hadoop"
os.environ["PATH"] = os.environ["HADOOP_HOME"] + "\\bin;" + os.environ.get("PATH", "")

import time
import pickle
import numpy as np
import pandas as pd
import psutil
from datetime import datetime, timezone

# Limit TensorFlow memory spam
os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"

from pyspark.sql import SparkSession
from pyspark.sql.functions import col, from_json
from pyspark.sql.types import StructType, StructField, StringType
import tensorflow as tf
from tensorflow.keras.preprocessing.sequence import pad_sequences
from elasticsearch import Elasticsearch

# ── Config ────────────────────────────────────────────────────────────────────
KAFKA_BROKER   = "localhost:9092"
KAFKA_TOPIC    = "sentiment-stream"
ES_HOST        = "http://localhost:9200"
ES_INDEX       = "sentiment_results"       # Where predictions go
ES_METRICS     = "performance_metrics"     # Where throughput data goes
MODEL_PATH     = "models/best_cnn_sentiment.keras"
TOKENIZER_PATH = "models/cnn_tokenizer.pkl"
MAX_LEN        = 100 # Adjusted to match your batch script length

# Standardized labels to match standard formats
LABEL_NAMES = {0: -1, 1: 0, 2: 1} 

print("Initializing PySpark Session...")
spark = SparkSession.builder \
    .appName("SparkCNNSentimentStream") \
    .config("spark.jars.packages", "org.apache.spark:spark-sql-kafka-0-10_2.12:3.5.0") \
    .config("spark.driver.host", "127.0.0.1") \
    .config("spark.driver.bindAddress", "127.0.0.1") \
    .getOrCreate()

# Suppress overly verbose Spark logging in the console
spark.sparkContext.setLogLevel("WARN")

# Load Models Globally so workers can use them
print(f"Loading CNN model: {MODEL_PATH}")
tf.config.set_visible_devices([], 'GPU') # Force CPU for safer streaming
global_model = tf.keras.models.load_model(MODEL_PATH)

print(f"Loading CNN tokenizer: {TOKENIZER_PATH}")
with open(TOKENIZER_PATH, "rb") as f:
    global_tokenizer = pickle.load(f)

es = Elasticsearch([ES_HOST])

# ── Spark micro-batch processing function ─────────────────────────────────────
def process_micro_batch(batch_df, batch_id):
    """
    This function runs on every new chunk of data Spark pulls from Kafka.
    """
    # 1. Convert Spark DataFrame to Pandas for easy Keras inference
    pdf = batch_df.toPandas()
    if pdf.empty:
        return
    
    batch_start_time = time.time()
    record_count = len(pdf)
    print(f"\n--- Processing Micro-Batch {batch_id} with {record_count} records ---")

    # 2. Tokenize and Pad Text
    # Make sure we fallback to empty string if review_text is null
    texts = pdf['review_text'].fillna("").astype(str).tolist()
    seqs = global_tokenizer.texts_to_sequences(texts)
    X_padded = pad_sequences(seqs, maxlen=MAX_LEN)

    # 3. Model Inference
    probs = global_model.predict(X_padded, verbose=0)
    preds = np.argmax(probs, axis=1)
    
    # 4. Standardize Data for Elasticsearch
    pdf['predicted_sentiment'] = [LABEL_NAMES.get(int(p), 0) for p in preds]
    pdf['mode'] = 'stream'
    pdf['timestamp'] = datetime.now(timezone.utc).isoformat()
    
    # 5. Calculate Metrics
    batch_end_time = time.time()
    processing_time = batch_end_time - batch_start_time
    throughput = record_count / processing_time if processing_time > 0 else 0
    
    cpu_usage = psutil.cpu_percent(interval=None)
    memory_usage = psutil.virtual_memory().percent
    
    # Accuracy logic: only calculate if true_label exists and is valid
    # Convert true_label to numeric if possible to check accuracy
    pdf['true_label_num'] = pd.to_numeric(pdf['true_label'], errors='coerce')
    valid_labels = pdf.dropna(subset=['true_label_num'])
    
    accuracy = 0.0
    if not valid_labels.empty:
        correct = (valid_labels['true_label_num'] == valid_labels['predicted_sentiment']).sum()
        accuracy = correct / len(valid_labels)

    print(f"Throughput: {throughput:.2f} records/sec | Accuracy: {accuracy:.2f}")

    # 6. Push Metrics to Elasticsearch
    metrics_doc = {
        "mode": "stream",
        "processing_time": float(processing_time),
        "throughput": float(throughput),
        "accuracy": float(accuracy),
        "cpu_usage": float(cpu_usage),
        "memory_usage": float(memory_usage),
        "timestamp": datetime.now(timezone.utc).isoformat(),
        "batch_id": batch_id
    }
    es.index(index=ES_METRICS, document=metrics_doc)

    # 7. Push Row-Level Data to Elasticsearch
    for _, row in pdf.iterrows():
        doc = {
            "review_id": str(row.get('review_id', '')),
            "review_text": str(row.get('review_text', '')),
            "true_label": int(row['true_label_num']) if not pd.isna(row['true_label_num']) else None,
            "predicted_sentiment": int(row['predicted_sentiment']),
            "mode": row['mode'],
            "timestamp": row['timestamp'],
"text_length": len(str(row.get('review_text', '')))
        } 
        es.index(index=ES_INDEX, document=doc)

# ── Spark Streaming Setup ─────────────────────────────────────────────────────
# Define the schema of the incoming Kafka JSON messages
kafka_schema = StructType([
    StructField("review_id", StringType(), True),
    StructField("review_text", StringType(), True),
    StructField("true_label", StringType(), True),
    StructField("timestamp", StringType(), True) # Source timestamp
])

print(f"Connecting to Kafka topic '{KAFKA_TOPIC}'...")

# Read from Kafka topic as a stream
raw_stream_df = spark.readStream \
    .format("kafka") \
    .option("kafka.bootstrap.servers", KAFKA_BROKER) \
    .option("subscribe", KAFKA_TOPIC) \
    .option("startingOffsets", "latest") \
    .load()

# Kafka data is binary. Cast 'value' to string and parse the JSON
parsed_stream_df = raw_stream_df \
    .selectExpr("CAST(value AS STRING)") \
    .select(from_json(col("value"), kafka_schema).alias("data")) \
    .select("data.*")

# Start the stream, sending every micro-batch to our Python function
print("Starting Spark Structured Streaming query...")
query = parsed_stream_df.writeStream \
    .foreachBatch(process_micro_batch) \
    .start()

query.awaitTermination()