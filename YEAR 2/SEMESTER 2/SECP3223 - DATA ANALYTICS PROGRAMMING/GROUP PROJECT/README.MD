# 🚗 Car CO₂ Emission Analysis & Classification — Data Analytics Project

A two-phase data analytics project that merges Malaysian and Canadian automotive datasets to analyse **CO₂ emission patterns** and build a **machine learning classifier** to predict vehicle emission categories.

---

## 👥 Group Members

| Name | Student ID |
|---|---|
| Nur Firzana binti Badrus Hisham | A23CS0156 |
| Nurul Adriana binti Kamal Jefri | A23CS0258 |
| Harini a/p Sangaan | A23CS0081 |

**Section:** 02 | **Course:** SECP 3223 — Data Analytics and Programming

---

## 📁 Project Structure

```
DAP Group Project/
├── Phase 1 .ipynb                    # Data preparation, cleaning & feature engineering
├── Phase 2.ipynb                     # Analytics, ML model & visualisations
│
├── FuelConsumption.csv               # Source dataset 1 — Canada 2014 CO2 emissions
├── cars_2025.csv                     # Source dataset 2 — Malaysia 2025 car registrations
├── Cleaned_Merged_Cars_FIXED.csv     # Output of Phase 1 — input for Phase 2
├── tips.csv                          # Supporting dataset for visualisations
│
└── Project SECP 3223 2024202502.pdf  # Project brief / rubric
```

---

## 📊 Datasets

| Dataset | Source | Records | Description |
|---|---|---|---|
| `FuelConsumption.csv` | Canada (2014) | ~1,000+ | CO2 emissions, engine size, fuel type, transmission |
| `cars_2025.csv` | Malaysia (2025) | ~15,000+ | Car maker, model, and registration data |
| `Cleaned_Merged_Cars_FIXED.csv` | Generated | — | Merged & cleaned output from Phase 1 |

---

## 🔬 Phase 1 — Data Preparation & Feature Engineering (`Phase 1 .ipynb`)

### Objectives
- Merge two datasets from different countries and years into a single clean dataset
- Engineer meaningful features for downstream analysis

### Steps Performed

**Part 1 — Dataset Matching & Cleaning**
- Loaded both CSVs using `pandas`
- Standardised `maker`/`MAKE` and `model`/`MODEL` columns (uppercase, stripped whitespace)
- Merged datasets on maker and model columns
- Exported result to `Cleaned_Merged_Cars_FIXED.csv`

**Part 2 — Feature Engineering & Aggregations**

New feature created:
- **`CO2_Emission_Category`** — categorises vehicles into `Low`, `Medium`, or `High` based on 33rd/66th percentile thresholds of CO2 emissions

8 aggregation summaries produced (average CO2 + fuel consumption grouped by):

| # | Grouped By |
|---|---|
| 1 | Vehicle Class |
| 2 | Engine Size |
| 3 | Number of Cylinders |
| 4 | Transmission Type |
| 5 | Fuel Type |
| 6 | Top 10 Car Makers by avg CO2 |
| 7 | Top 10 Car Models by avg CO2 |
| 8 | CO2 Emission Category |

---

## 🤖 Phase 2 — Analytics, Machine Learning & Visualisations (`Phase 2.ipynb`)

### Part 1 — Descriptive Analytics

Statistical summary of CO2 emissions:
- Mean, Median, Min, Max, Std Deviation
- Maker & fuel type frequency counts
- **Outlier Detection** using IQR method — identified 1,643 outliers

Key findings:
- Mean CO2 Emission: **185.49 g/km**
- Range: **161 – 437 g/km**
- Most prolific maker: **Honda** (14,925 records)

### Part 2 — Machine Learning (Random Forest Classifier)

| Item | Detail |
|---|---|
| Model | `RandomForestClassifier` (scikit-learn) |
| Target | `CO2_Emission_Category` (Low / Medium / High) |
| Features | Engine Size, Cylinders, Fuel Type, Transmission, Vehicle Class |
| Split | 80% train / 20% test |
| Preprocessing | `StandardScaler` (numerical) + `OneHotEncoder` (categorical) via `ColumnTransformer` |
| Pipeline | `sklearn.pipeline.Pipeline` |
| **Accuracy** | **~100%** (near-perfect classification) |

All classes (Low / Medium / High) achieved **precision, recall, and F1-score of 1.00**.

### Part 3 — Visualisations

Built using `seaborn` and `matplotlib`:
- Bar plot: Top 10 car makers by registration count
- Emission distribution plots by category
- Supporting charts from `tips.csv`

---

## 🛠️ Tech Stack

| Tool | Purpose |
|---|---|
| Python 3 (Conda) | Programming language |
| Jupyter Notebook | Interactive development environment |
| pandas | Data loading, cleaning, merging |
| numpy | Numerical operations |
| scikit-learn | ML model, preprocessing, evaluation |
| seaborn | Statistical visualisations |
| matplotlib | Plot rendering |

---

## ⚙️ How to Run

### 1. Install Dependencies

```bash
pip install pandas numpy scikit-learn seaborn matplotlib jupyter
```

Or with conda:
```bash
conda install pandas numpy scikit-learn seaborn matplotlib jupyter
```

### 2. Run Phase 1 First

```bash
jupyter notebook "Phase 1 .ipynb"
```

Run all cells — this generates `Cleaned_Merged_Cars_FIXED.csv` which Phase 2 depends on.

### 3. Run Phase 2

```bash
jupyter notebook "Phase 2.ipynb"
```

> ⚠️ **Phase 2 will fail if `Cleaned_Merged_Cars_FIXED.csv` does not exist.** Always run Phase 1 first, or ensure the cleaned CSV is present in the same directory.

---

## 📌 Notes

- Both notebooks must be in the **same folder** as the CSV files
- The project uses a **Conda base environment** — a `conda` setup is recommended for full compatibility
- `Cleaned_Merged_Cars_FIXED.csv` is auto-generated and does not need to be committed to Git (see `.gitignore`)

---

*SECP 3223 — Data Analytics and Programming | Universiti Teknologi Malaysia | 2024/2025 Sem 2*
