# 🧮 SimpleCalc — Object-Oriented Calculator in C++

A beginner C++ console application that demonstrates **Object-Oriented Programming (OOP)** fundamentals through a simple arithmetic calculator. Built using a custom `SimpleCalc` class with encapsulation and multi-file structure.

---

## 📁 Project Structure

```
lab 1/
├── main.cpp          # Entry point — takes user input and displays results
├── SimpleCalc.h      # Class declaration (header file)
├── SimpleCalc.cpp    # Class implementation
└── .vscode/
    └── tasks.json    # Build tasks for VS Code (MinGW)
```

---

## 🧱 OOP Concepts Demonstrated

| Concept | How It's Applied |
|---|---|
| **Class & Object** | `SimpleCalc` class is declared in `.h` and defined in `.cpp` |
| **Encapsulation** | `num1` and `num2` are `private`; accessed only through public methods |
| **Constructor** | `SimpleCalc(double n1, double n2)` initialises both operands |
| **Member Functions** | `add()`, `subtract()`, `multiply()`, `divide()` as public methods |
| **Multi-file Structure** | Separation of header, implementation, and driver files |

---

## 🛠️ Tech Stack

| Item | Detail |
|---|---|
| Language | C++ |
| Compiler | MinGW g++ |
| IDE | Visual Studio Code |
| Platform | Windows |

---

## ⚙️ Prerequisites

- MinGW g++ installed and added to PATH
- Visual Studio Code with the C/C++ extension

---

## 🚀 How to Build & Run

### Option A — VS Code

1. Open the `lab 1/` folder in VS Code
2. Press `Ctrl+Shift+B` → select **`multi_file_console_build`**
3. Run the generated `SimpleCalc.exe` in your terminal

### Option B — Command Line

```bash
cd "lab 1"
g++ -g *.cpp -o SimpleCalc
./SimpleCalc
```

---

## 🖥️ Expected Output

```
Enter 2 numbers: 10 2
The result of addition is: 12
The result of subtraction is: 8
The result of multiplication is: 20
The result of division is: 5
```

---

## 📌 Notes

- Division by zero is handled — returns `0` if `num2 == 0`
- Both operands accept `double` values (supports decimals)

---

*Data Structure & Algorithm | Universiti Teknologi Malaysia*
