# 🧠 Tutorial III: AI Algorithm — Image Classification using CNN

<p align="center">
  <img src="https://img.shields.io/badge/Python-3.x-blue?style=flat-square&logo=python" />
  <img src="https://img.shields.io/badge/TensorFlow-2.x-orange?style=flat-square&logo=tensorflow" />
  <img src="https://img.shields.io/badge/Keras-Deep%20Learning-red?style=flat-square&logo=keras" />
  <img src="https://img.shields.io/badge/CIFAR--10-Dataset-green?style=flat-square" />
  <img src="https://img.shields.io/badge/Google%20Colab-Notebook-yellow?style=flat-square&logo=googlecolab" />
</p>

> **SECP3843 — Special Topic in Data Engineering (WBL)**  
> Faculty of Computing, Universiti Teknologi Malaysia  
> **Lecturer:** Dr. Aryati Binti Bakri

---

## 👥 Group 8

| Name | Matric No | Role |
|------|-----------|------|
| Yasmin Batrisyia Binti Zahiruddin | A23CS0201 | Person 1 — Theory Lead |
| Syarifah Dania Binti Syed Abu Bakar | A23CS0183 | Person 2 — Developer Lead |
| Nurul Adriana Binti Kamal Jefri | A23CS0258 | Person 3 — Analysis Lead |

---

## 📌 Project Overview

This project explores **image classification** using **Convolutional Neural Networks (CNN)** on the [CIFAR-10](https://www.cs.toronto.edu/~kriz/cifar.html) dataset. Three models were built and compared:

1. **ANN (Baseline)** — a fully-connected Artificial Neural Network
2. **CNN** — a standard Convolutional Neural Network following a YouTube tutorial
3. **Enhanced CNN** — an improved CNN with deeper architecture and regularisation techniques

The goal was to demonstrate why CNNs outperform ANNs for image classification, and how targeted enhancements further boost performance.

---

## 📊 Dataset

| Property | Details |
|----------|---------|
| Name | CIFAR-10 |
| Source | `tensorflow.keras.datasets.cifar10` |
| Training samples | 50,000 images |
| Test samples | 10,000 images |
| Image size | 32 × 32 × 3 (RGB) |
| Classes | 10 (airplane, automobile, bird, cat, deer, dog, frog, horse, ship, truck) |

---

## 🏗️ Model Architecture

### 1. ANN (Baseline)
- Flatten → Dense(3072) → Dense(10, softmax)
- No spatial feature extraction
- **Test Accuracy: 46.00%**

### 2. CNN
- Conv2D(32) → MaxPool → Conv2D(64) → MaxPool → Flatten → Dense(64) → Dense(10, softmax)
- 10 epochs, trained on raw normalised images
- **Test Accuracy: 70.36%** | Test Loss: 0.9700

### 3. Enhanced CNN ⭐
- **3 convolutional blocks** (32 → 64 → 128 filters)
- **2× Conv2D per block** (stacked layers for richer feature extraction)
- **BatchNormalization** after every Conv2D layer
- **Dropout(0.25)** after each conv block, **Dropout(0.5)** before output
- **Data Augmentation** (rotation, shift, horizontal flip)
- Dense(256) head with BatchNorm + Dropout
- 10 epochs with `datagen.flow()`, batch size 64
- **Test Accuracy: 78.48%** | Test Loss: 0.6348

---

## 📈 Results Summary

| Model | Test Accuracy | vs ANN Baseline |
|-------|:-------------:|:---------------:|
| ANN (Baseline) | 46.00% | — |
| CNN | 70.36% | +24.4% |
| Enhanced CNN | 78.48% | +32.5% |

---

## 🔧 Enhancements Applied

| Technique | Purpose |
|-----------|---------|
| **Data Augmentation** | Prevents overfitting by exposing the model to randomly transformed images each epoch |
| **Batch Normalization** | Stabilises and accelerates training by normalising layer activations |
| **Dropout (0.25 / 0.5)** | Randomly deactivates neurons during training to reduce co-dependency |
| **Deeper Conv Blocks** | Extracts higher-level abstract features via an additional 128-filter block |
| **Stacked Conv2D Layers** | Two conv layers per block capture richer local patterns before pooling |

---

## 🗂️ Repository Structure

```
Tutorial-3-AI-CNN/
│
├── image_class_using_cnn.ipynb   # Main Google Colab notebook (all cells)
├── Group_8_Tutorial_Report.pdf   # Final submitted report
└── README.md                     # This file
```

---

## 🚀 How to Run

### Option A — Google Colab (Recommended)
1. Open `image_class_using_cnn.ipynb` in [Google Colab](https://colab.research.google.com/)
2. Go to **Runtime → Run all**
3. CIFAR-10 will be downloaded automatically via Keras (~170 MB)

### Option B — Local (Jupyter Notebook)
```bash
# 1. Clone the repo
git clone https://github.com/<your-username>/Tutorial-3-AI-CNN.git
cd Tutorial-3-AI-CNN

# 2. Install dependencies
pip install tensorflow matplotlib seaborn scikit-learn numpy

# 3. Launch notebook
jupyter notebook image_class_using_cnn.ipynb
```

---

## 📦 Dependencies

```
tensorflow >= 2.x
numpy
matplotlib
seaborn
scikit-learn
```

---

## 📋 Notebook Structure

| Cell | Description |
|------|-------------|
| 1–2 | Import libraries & load CIFAR-10 dataset |
| 3–5 | Explore dataset shapes & class labels |
| 6–10 | Define classes & helper functions |
| 11–12 | Visualise sample training images |
| 13 | Normalise pixel values (÷ 255) |
| 14–15 | Build, train & evaluate ANN baseline |
| 16–17 | ANN classification report & confusion matrix |
| 18–21 | Build, train & evaluate original CNN |
| 22–27 | Visualise CNN predictions on test samples |
| 28 | **[Enhancement]** Data Augmentation setup |
| 29 | **[Enhancement]** Enhanced CNN architecture |
| 30 | **[Enhancement]** Train Enhanced CNN |
| 31 | **[Enhancement]** Evaluate Enhanced CNN |
| 32 | **[Enhancement]** Comparison table & bar chart |

---

## 🔍 Key Findings

- CNNs are fundamentally superior to ANNs for image classification because they preserve and exploit **spatial relationships** between pixels through convolutional filters.
- The original CNN reduced overfitting versus ANN but still showed a ~10% gap between training (80.41%) and test (70.36%) accuracy.
- The Enhanced CNN narrowed this gap to ~3.6% (train: 74.85%, test: 78.48%), confirming that Dropout and data augmentation effectively controlled overfitting.
- Batch Normalization contributed to faster convergence — val_accuracy surpassed the original CNN's final test accuracy as early as **Epoch 5**.

---

*SECP3843 Special Topic in Data Engineering — Universiti Teknologi Malaysia*
