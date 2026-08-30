import time
import pickle
import numpy as np
import pandas as pd
import psutil
from datetime import datetime, timezone
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing.sequence import pad_sequences
from sklearn.metrics import accuracy_score
from elasticsearch import Elasticsearch

print("Starting Batch Pipeline initialization...")

# 1. Start the Performance Clock
start_time = time.time()

# 2. Read Your Cleaned Data
print("Loading cleaned_data.csv...")
pdf = pd.read_csv("data/cleaned_data.csv")
record_count = len(pdf)
print(f"Loaded {record_count} rows.")

# 3. Load your Saved Colab Assets
print("Loading CNN Model and Tokenizer...")
with open("models/cnn_tokenizer.pkl", "rb") as f:
    tokenizer = pickle.load(f)
model = load_model("models/best_cnn_sentiment.keras")

# 4. Apply Tokenization Sequences
print("Converting text sequences...")
sequences = tokenizer.texts_to_sequences(pdf['clean_review'].fillna("").astype(str))
X = pad_sequences(sequences, maxlen=100)

# 5. Run Model Evaluation
print("Running batch predictions...")
predictions = model.predict(X)
predicted_indices = np.argmax(predictions, axis=1)

# Map the model's softmax class indices (0,1,2) back to the actual sentiment scale
index_to_label = {0: -1, 1: 0, 2: 1}
# UPDATED FIELD: predicted_sentiment
pdf['predicted_sentiment'] = [index_to_label[i] for i in predicted_indices]

# 6. Complete Metrics Computations
end_time = time.time()
processing_time = end_time - start_time
throughput = record_count / processing_time

# Accuracy check
accuracy = accuracy_score(pdf['label'], pdf['predicted_sentiment'])
cpu_usage = psutil.cpu_percent(interval=0.5)
memory_usage = psutil.virtual_memory().percent

# Add Metadata & UPDATE FIELD: true_label
pdf['mode'] = 'batch'
pdf['timestamp'] = datetime.now(timezone.utc)
pdf = pdf.rename(columns={'label': 'true_label'})

# 7. Send Everything to Elasticsearch
print("Storing documents in local Elasticsearch...")
es = Elasticsearch(["http://localhost:9200"])

# UPDATED CLEARING LOGIC: Only delete 'batch' records, keep 'stream' records safe
print("Clearing previous batch run's data...")
es.delete_by_query(
    index="sentiment_results", 
    body={"query": {"match": {"mode": "batch"}}}, 
    ignore_unavailable=True
)
es.delete_by_query(
    index="performance_metrics", 
    body={"query": {"match": {"mode": "batch"}}}, 
    ignore_unavailable=True
)

# Push Batch metrics
metrics_doc = {
    "mode": "batch",
    "processing_time": float(processing_time),
    "throughput": float(throughput),
    "accuracy": float(accuracy),
    "cpu_usage": float(cpu_usage),
    "memory_usage": float(memory_usage),
    "timestamp": datetime.now(timezone.utc).isoformat()
}
es.index(index="performance_metrics", document=metrics_doc)

# Bulk send the data rows to the UNIFIED index
print("Indexing row-level predictions...")
for index, row in pdf.iterrows():
    doc = {
        "review_id": int(index),
        "review_text": str(row['clean_review']),
        "true_label": int(row['true_label']),
        "predicted_sentiment": int(row['predicted_sentiment']),
        "mode": row['mode'],
        "timestamp": row['timestamp'].isoformat(),
	"text_length": len(str(row.get('review_text', '')))
    }
    es.index(index="sentiment_results", document=doc)

print("\nBatch Processing Successfully Finished!")
print(f"Throughput achieved: {throughput:.2f} rows/sec")
print(f"Accuracy achieved: {accuracy:.2f}")