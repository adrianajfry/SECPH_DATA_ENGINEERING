# 🦠📝 Analyzing Global COVID-19 Vaccination Disparities: A Local Spark-Based Data Lakehouse Pipeline

Individual case study — SECP (Faculty of Computing, Universiti Teknologi Malaysia)
**Author:** Nurul Adriana Binti Kamal Jefri

## Overview

This project integrates five publicly available datasets — COVID-19 vaccination records, daily case/death counts, population statistics, the Oxford COVID-19 Government Response Tracker (OxCGRT) stringency index, and World Bank Income Classification — into a single analysis-ready table using a Spark-based bronze-silver-gold medallion pipeline. The integrated data is used to compare vaccination rate per capita, case-fatality rate, and government policy stringency across four World Bank income tiers (High, Upper-Middle, Lower-Middle, Low Income), surfaced through an interactive Power BI dashboard.

The pipeline was originally designed for Azure Databricks + ADLS Gen2, then fully re-implemented to run on a local Windows machine using PySpark.

## Environment

| Component | Version / Detail |
|---|---|
| OS | Windows 11 |
| IDE | Visual Studio Code + Jupyter Notebook extension |
| Python | 3.11 |
| PySpark | 3.5.3 (Spark master `local[*]`) |
| Java | Eclipse Adoptium / Microsoft Build of OpenJDK 17 |
| Hadoop native libs | `winutils.exe` + `hadoop.dll` (Hadoop 3.3.x, matched pair — required for Spark's Windows file I/O layer even without HDFS) |

### Known local-setup gotchas (see project notes for full troubleshooting)
- `winutils.exe` and `hadoop.dll` must come from the **same** Hadoop build/source — mixing versions causes native library errors.
- `JAVA_HOME` / `HADOOP_HOME` must be set as **System** (not just User) environment variables, and VS Code must be fully restarted (not just the terminal) to pick them up.
- The JDK must be installed at a path **without spaces** (e.g. `C:\Java\jdk-17`, not `C:\Program Files\...`) — Spark's Windows launcher scripts don't reliably quote paths, causing an intermittent `FileNotFoundError` on `SparkSession.getOrCreate()`.
- Any stray `SPARK_HOME` environment variable pointing at an incomplete/incorrect Spark install will override PySpark's own bundled launcher scripts — unset it and let PySpark use its bundled `bin/` scripts.

## Data Sources

| Dataset | Source | Notes |
|---|---|---|
| COVID-19 World Vaccination Progress | Kaggle (Preda) | Daily, 2020–2022; filtered to exclude OWID sub-national codes (`OWID_ENG`, `OWID_SCT`, etc.) |
| COVID-19 Cases and Deaths (`full_grouped.csv`) | Kaggle, "Corona Virus Report" (imdevskp) | Daily, per-country; no ISO-3 code — resolved via a two-stage name→ISO mapping (direct match, then ~90-entry manual lookup table) |
| World Population Dataset | Kaggle | Static; 2020 population used as the per-capita baseline |
| OxCGRT Stringency Index | Oxford BSG | Daily; filtered to `Jurisdiction == "NAT_TOTAL"` only, to avoid state/city-level duplicate rows |
| World Bank Income Classification | World Bank (`.xlsx`) | Read via `pandas` from the **"List of economies"** sheet (not "composition"), then converted to a Spark DataFrame |

All five join on ISO-3 country code; three (vaccination, cases/deaths, OxCGRT) also share a date field for temporal joins. Population and World Bank classification are static, joined on country code alone.

## Pipeline / Notebooks

Run in this order (matches numbering after a rename to fix the original dependency mismatch):

1. `00_config.ipynb` — verifies local Java/Hadoop/winutils setup, defines bronze/silver/gold paths, initializes the shared local SparkSession
2. `01_silver_vaccination.ipynb`
3. `02_silver_worldbank.ipynb` — reads the World Bank `.xlsx` via pandas
4. `03_silver_population.ipynb`
5. `04_silver_oxcgrt.ipynb`
6. `05_silver_cases_deaths.ipynb` — depends on `02_silver_worldbank` for name resolution
7. `06_gold_integrated.ipynb` — joins all five silver tables, runs data quality checks, writes the gold table (Parquet + CSV export)

Each notebook starts with:
```python
%run "./00_config.ipynb"
```
to share the same SparkSession and path variables.

### Folder structure (local)
```
C:\covid_pipeline\
├── bronze\   # raw source files, unmodified
├── silver\   # cleaned, standardized per-source Parquet
└── gold\     # gold_integrated (Parquet) + gold_final_csv (for Power BI)
```

## Gold Table

- **84,056 rows × 23 columns**
- Zero duplicate `iso_code + date` combinations
- 53.2% null rate on vaccination-rate field (early rollout reporting gaps, Dec 2020–Feb 2021) — retained, not dropped, per medallion lineage principle
- 205 of 217 countries matched to a World Bank income group (remaining are micro-states/disputed territories not in the World Bank list)
- 96.3% null rate on OxCGRT stringency index (OxCGRT covers ~180 of the broader country list)

## Dashboard (Power BI)

Data modeled as a **star schema**:
- `fact_vaccination` — country-date grain, all measures (vaccination counts, cases, deaths, stringency indices)
- `dim_country` — 217 rows, one per country (`iso_code`, `country`, `continent`, `income_group`, `wb_region`)
- `dim_date` — one row per date, with derived `Year` / `Month` / `Month Name` columns

**Visuals:**
1. World map — avg. vaccination rate per 100 people, coloured by income group
2. Clustered bar chart — avg. vaccination rate by income tier
3. Line chart — avg. vaccination rate over time by income group
4. Scatter plot — avg. stringency index vs. avg. vaccination rate, by country/income group
5. Summary cards — overall avg. vaccination rate, countries covered, avg. stringency index

Filterable via a tile-style slicer on `income_group`.

## Key Results

| Income Tier | Avg. Vaccination Rate (per 100 people) |
|---|---|
| High Income | ~49 |
| Upper-Middle Income | ~36 |
| Lower-Middle Income | ~22 |
| Low Income | ~5 |

Overall avg. vaccination rate: 39.91 · Countries covered: 205 · Avg. stringency index: 61.37

## Known Limitations

- Low Income countries are under-represented in the stringency-vs-vaccination scatter plot — most plausibly an OxCGRT data-coverage artifact (96.3% null rate concentrated among less internationally-tracked countries), not evidence of an absent policy response.
- No AI/ML component — this is a data integration and descriptive-analytics study; a regression model (income tier + stringency + population density → vaccination rate) is a natural extension, not implemented here.
- Population baseline fixed at 2020 (no year-matched population data available in the source file, which only publishes population at ~5-year/ irregular intervals).

## Future Work

- Automate ingestion for repeated local runs
- Extend dataset coverage to the full outbreak period
- Close remaining OxCGRT coverage gaps where possible
- Apply regression analysis to formally quantify the relative contribution of income level, policy stringency, and disease burden to vaccination outcomes

## Acknowledgment

Thanks to Dr. Aryati Bakri for guidance and feedback throughout this study.
