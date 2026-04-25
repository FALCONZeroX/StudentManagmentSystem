<p align="center">
  <img src="https://img.shields.io/badge/Version-1.2.0-blue?style=for-the-badge" alt="Version">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B" alt="Language">
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey?style=for-the-badge" alt="Platform">
  <img src="https://img.shields.io/badge/Architecture-Modular-orange?style=for-the-badge" alt="Architecture">
</p>

---

## 📝 Introduction

The **Advanced Student Management System** is a robust terminal-based application designed to streamline academic record-keeping. Unlike basic management scripts, this project utilizes a **Modular Programming** approach, separating declaration from implementation to ensure scalability and clean code standards.

Developed by **FΛLCØN**, this system is optimized for performance, using efficient data structures like `std::vector` and implementing persistent storage through advanced file handling.

---

## 🚀 Core Features

### 1. Comprehensive Record Management (CRUD)
* **Add Students**: Register new students with details (Name, Roll Number, Department, cGPA, Semester, Status).
* **Search System**: Intelligent search using Roll Number or Name (Case-Insensitive).
* **Update/Delete**: Modify existing records or remove them with real-time file synchronization.

### 2. Data Analytics & Statistics
The system provides a built-in analytical engine that generates:
* **Departmental Reports**: Distribution of students across IT, CS, ME, EE, and CE.
* **Academic Performance**: Categorization based on cGPA (Excellent, Very Good, Good, etc.).
* **Enrollment Status**: Track active vs. inactive students.

### 3. Advanced Sorting & Filtering
* Sort records by **Name** (Alphabetical).
* Sort by **cGPA** (Top Performers).
* Sort by **Semester** (Ascending/Descending).

### 4. System Integrity
* **Input Validation**: Uses `Clear_Buffer()` to prevent infinite loops from invalid inputs.
* **Persistence**: Uses `fstream` to ensure all data is saved to a permanent database file.

---

## 📁 File Structure & Architecture

The project is structured into three files to promote **Encapsulation** and **Modularity**:

### 1. `student.h` (The Blueprint)
Contains the core structure and function declarations.
* Defines `struct stStudents`.
* Includes constant definitions for departments.
* Declares all functional prototypes.

### 2. `student.cpp` (The Engine)
The implementation file containing the logic for:
* File Input/Output operations.
* Data transformation and validation.
* Analytical calculations.
* Sorting algorithms logic.

### 3. `main.cpp` (The Controller)
The entry point of the application:
* Manages the main execution loop.
* Handles user navigation and menu rendering.
* Coordinates calls between the UI and the backend logic.

---

## 🛠️ Installation & Setup

### Prerequisites
* A C++ compiler supporting **C++11** or later (GCC, Clang, or MSVC).
* Any modern Terminal/Command Prompt.

### Step-by-Step Guide

1. **Clone the Repository**:
   ```bash
   git clone [https://github.com/YourUsername/Student-Management-System.git](https://github.com/YourUsername/Student-Management-System.git)
   cd Student-Management-System

```
 2. **Compilation**:
   To compile the project with all its dependencies, use the following command:
   ```bash
   g++ main.cpp student.cpp -o SMS_App
   
   ```
 3. **Execution**:
   ```bash
   # For Windows:
   SMS_App.exe
   
   # For Linux/macOS:
   ./SMS_App
   
   ```
## 💻 Code Snippets & Logic
### Case-Insensitive Search
The system implements a robust search logic:
```cpp
string Convert_To_Lower(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

```
### Modular Compilation Hint
When working with multiple files, ensure both .cpp files are included in the build command to avoid "Undefined Reference" errors.
## 📊 Feature Comparison
| Feature | Student System v1.2 | Basic Systems |
|---|---|---|
| Modular Structure | ✅ Yes | ❌ No |
| File Persistence | ✅ Binary/Text | ❌ No |
| Sorting Logic | ✅ 3+ Methods | ❌ Fixed |
| Input Validation | ✅ Robust | ❌ Weak |
## 👤 Developer Profile
**FΛLCØN**
 * 🛠️ **Role**: IT Student & Aspiring Software Engineer.
 * 🎨 **Expertise**: Graphic Design & Low-level C++ Optimization.
 * 📍 **Location**: Yemen.
 * 📚 **Education**: Following the "Programming Advices" Curriculum by Dr. Mohammed Abu-Hadhoud.
## 🛡️ License
This project is licensed under the MIT License - see the LICENSE file for details.
## 📞 Support & Contact
If you find a bug or have a feature request, please open an issue on the GitHub repository or contact the developer via the official student committee bot.
> "Quality is not an act, it is a habit." - *Coding the future, one line at a time.*
> 
<p align="center">
<b>© 2026 FΛLCØN. All Rights Reserved.</b>
</p>
```

```
