<h1 align="center">
  📰 MalayMail News Scraper & Data Pipeline Optimization
  <br>
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Python-3776AB?logo=python&logoColor=white" alt="Python">
  <img src="https://img.shields.io/badge/Playwright-2EAD33?logo=playwright&logoColor=white" alt="Playwright">
  <img src="https://img.shields.io/badge/Pandas-150458?logo=pandas&logoColor=white" alt="Pandas">
  <img src="https://img.shields.io/badge/Dask-FC6E6B?logo=dask&logoColor=white" alt="Dask">
  <img src="https://img.shields.io/badge/Polars-CD792C?logo=polars&logoColor=white" alt="Polars">
</p>

<table border="solid" align="center">
  <tr>
    <th>Name</th>
    <th>Matric Number</th>
  </tr>
  <tr>
    <td width=80%>NURUL ADRIANA BINTI KAMAL JEFRI</td>
    <td>A23CS0258</td>
  </tr>
  <tr>
    <td width=80%>TAN YI YA</td>
    <td> A23CS0187</td>
  </tr>
  <tr>
    <td width=80%>TEH RU QIAN</td>
    <td>A23CS0191</td>
  </tr>
</table>

---

## 🎯 Project Overview
This project focuses on building an automated web scraping architecture and a high-performance data processing pipeline. We extracted over 120,000 news articles from the Malay Mail website and subjected the raw data to a rigorous cleaning phase (fixing encoding, deduplication, regex extraction, and type casting). 

To solve the single-threaded bottleneck of standard data manipulation, we benchmarked the pipeline across three different frameworks: **Pandas (Baseline)**, **Dask (Distributed)**, and **Polars (Multi-threaded Rust)** to determine the ultimate processing engine for medium-to-large textual datasets.

---

## 📂 Project Files

| File Name                     | Description                                                | Link |
|------------------------------|------------------------------------------------------------|------|
| **Raw Dataset** | Cleaned and raw data with URLs                             | [![Download](https://img.shields.io/badge/Download-Drive-blue?logo=google-drive)](#) |
| **Clean Dataset** | Preprocessed data ready for use                            | [![Download](https://img.shields.io/badge/Download-Drive-blue?logo=google-drive)](#) |
| **Web Crawler Script** | Python script to scrape MalayMail                          | [![Open](https://img.shields.io/badge/View-Code-green?logo=jupyter)](#) |
| **Optimization Code** | Script to clean, preprocess and benchmark the frameworks   | [![Open](https://img.shields.io/badge/View-Code-green?logo=jupyter)](#) |
| **Pandas Record** | Benchmark results Pandas                                   | [![Open](https://img.shields.io/badge/View-CSV-orange?logo=csv)](#) |
| **Dask Record** | Benchmark results Dask                                     | [![Open](https://img.shields.io/badge/View-CSV-orange?logo=csv)](#) |
| **Polars Record** | Benchmark results Polars                                   | [![Open](https://img.shields.io/badge/View-CSV-orange?logo=csv)](#) |
| **Project Report** | Final detailed documentation                               | [![Download](https://img.shields.io/badge/Download-PDF-red?logo=adobe-acrobat-reader)](#) |

---

## 🛠️ System Architecture

### 🕸️ Web Scraping Architecture
We utilized **Playwright** to bypass dynamic rendering and bot-detection. To prevent memory exhaustion crashes (`pipe closed by peer`), the scraper was designed as an "Append-Only" engine, securely saving data in batches while respecting server pagination limits.

### ⚙️ Data Processing Pipeline
The raw data passes through 6 distinct cleaning nodes:
1. **Safe Ingestion:** Forcing string schemas to prevent immediate pipeline crashes on messy web data.
2. **Encoding Repairs:** Chaining string replacements to fix corrupted UTF-8 mojibake.
3. **Deduplication:** Dropping duplicate articles while retaining the earliest published record.
4. **Standardization:** Trimming whitespaces and standardizing categories.
5. **Regex Extraction:** Using Structs/Dictionaries to parse physical "Locations" directly out of the text body.
6. **Validation:** Dropping critical nulls and casting final text types.

---
## 🛠️ System Architecture
<img width="1863" height="2346" alt="System Architecture" src="https://github.com/user-attachments/assets/4b22b316-8035-4696-bd58-6d592035d993" />

---

## 📊 Dataset Overview
Original dataset containing **121,794** news articles collected across multiple categories (Sports, Showbiz, Tech, etc.). The raw dataset consists of **9 columns**. 

After passing through the optimization pipeline, the final cleaned dataset consists of **10 columns** (including the newly extracted `location` field) and zero missing critical values.

| Column Name        | Description                                                              |
|--------------------|--------------------------------------------------------------------------|
| `id`               | Unique article identifier                                                |
| `title`            | News title                                                               |
| `category`         | News category                                                            |
| `day`              | Publication day                                                          |
| `date`             | Publication date                                                         |
| `time`             | Publication time                                                         |
| `author`           | Author name                                                              |
| `location`         | Extracted article location (Generated during pipeline)                   |
| `content`          | News article content body                                                |
| `link`             | Original Article URL                                                     |

---

## 🚀 Performance Benchmark

We performed five test runs for each optimization stage using **Pandas**, **Dask**, and **Polars**, tracking four key performance metrics.

### 📈 Performance Visualizations
<img width="619" height="371" alt="execution time chart" src="https://github.com/user-attachments/assets/07742596-5a90-4a79-93cb-ba8586804b24" />
<img width="620" height="367" alt="memory footprint chart" src="https://github.com/user-attachments/assets/f8039f95-2945-4bab-82fa-8381803ca651" />


### 🕒 Total Processing Time (seconds)

| Tools    | Run 1 | Run 2 | Run 3 | Run 4 | Run 5 | **Average** |
|----------|-------|-------|-------|-------|-------|-------------|
| **Pandas** | 25.82 | 25.44 | 25.71 | 26.10 | 24.15 | **25.65** |
| **Dask** | 154.50| 150.52| 155.19| 148.45| 152.90| **152.31** |
| **Polars** | 10.89 | 4.94  | 5.93  | 4.74  | 4.53  | **6.21** |


### 🧠 CPU Usage (%)

| Tools                | Run 1 | Run 2 | Run 3 | Run 4 | Run 5 | **Average** |
|----------------------|-------|-------|-------|-------|-------|-------------|
| Pandas | 61.9 | 63.1 | 54.5 | 60.8 | 53.2 | **59.8**    |
| Dask | 70.10 | 69.70 | 69.10 | 68.90 | 73.10 | **70.18**    |
| Polars | 90.20 | 61.20 | 96.00 | 44.40 | 55.00 | **69.36**    |


### 💾 Memory Usage (MB)

| Tools                | Run 1 | Run 2 | Run 3 | Run 4 | Run 5 | **Average** |
|----------------------|-------|-------|-------|-------|-------|-------------|
| Pandas | 1872.0 | 2276.5 | 2570.5 | 2595.5 | 2609.1 | **2239.7**    |
| Dask | 3876.40 | 4747.00 | 4800.30 | 4652.70 | 4815.40 | **4578.36**    |
| Polars | 5204.00 | 5798.30 | 6174.00 | 6447.80 | 6490.10 | **6022.84**    |


### ⚡ Throughput (records/second)

| Tools    | Run 1 | Run 2 | Run 3 | Run 4 | Run 5 | **Average** |
|----------|-------|-------|-------|-------|-------|-------------|
| **Pandas** | 4782  | 4854  | 4804  | 4731  | 5114  | **4813** |
| **Dask** | 799   | 820   | 796   | 832   | 808   | **811** |
| **Polars** | 11336 | 24952 | 20796 | 26020 | 27244 | **22069** |

---

## 📈 Performance Comparison between Libraries
<img width="690" height="474" alt="Full Chart" src="https://github.com/user-attachments/assets/e69cecfa-bff7-44a5-b587-5adc37707b35" />

---

## ✅ Conclusion
The benchmark results clearly demonstrate the impact of different data processing architectures on pipeline efficiency:

- **Pandas (The Baseline):** Pandas delivered a solid, reliable baseline, processing the dataset in an average of 25.6 seconds. Because it relies on single-threaded execution, its CPU utilization was the lowest (~59.8%), maintaining a low memory footprint (2,239 MB).
- **Dask (The Overhead Penalty):** Dask performed significantly slower than the baseline, averaging 152.3 seconds. While Dask successfully utilized more CPU cores (70.18%), the ~120,000-row dataset was not large enough to benefit from its distributed architecture. The massive scheduling overhead required to partition the data and manage the parallel workers severely bottlenecked the execution speed.
- **Polars (The Speed Multiplier):** Polars drastically outperformed both frameworks. By leveraging its Rust-based engine, lazy evaluation, and Apache Arrow memory format, Polars parallelized the workload perfectly. It processed the entire dataset in just 6.2 seconds, achieving a massive throughput of over 22,069 records/second (a **358% speed increase** over Pandas). 

## 🥇 Winner
<p align="center">
  <img src="https://raw.githubusercontent.com/pola-rs/polars-static/master/logos/polars-logo-dark.svg" width="300px"/>
</p>

**Polars** is the definitive winner for this pipeline. It maximized our hardware's multi-threading capabilities, sidestepped the single-core limitations of Pandas, and avoided the heavy task-graph overhead of Dask, proving to be the ultimate high-performance solution for medium-to-large web-scraped datasets.
