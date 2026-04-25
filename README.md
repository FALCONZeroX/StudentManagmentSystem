# 🎓 Student Management System

![C++](https://img.shields.io/badge/C++-17-blue.svg?style=flat&logo=c%2B%2B)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Version](https://img.shields.io/badge/Version-1.0.0-brightgreen)

A comprehensive console-based **Student Records Management System** written in C++.  
It allows you to efficiently manage student data with full CRUD operations, advanced search, sorting, statistics, import/export, and local binary file persistence.

---

## 📋 Table of Contents

- [✨ Features](#-features)
- [📸 Screenshots](#-screenshots)
- [📁 Project Structure](#-project-structure)
- [🚀 Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
  - [Running the Program](#running-the-program)
- [💻 Usage](#-usage)
- [🔧 Function Modules](#-function-modules)
  - [Main Menu Options](#main-menu-options)
  - [Data Validation](#data-validation)
  - [Persistence](#persistence)
- [📊 Data Flow & Storage](#-data-flow--storage)
- [🧪 Testing](#-testing)
- [🤝 Contributing](#-contributing)
- [📝 License](#-license)
- [📧 Contact](#-contact)

---

## ✨ Features

- **Add New Student**: Complete form with real-time validation for all fields (name, department, semester, cGPA, date of birth, phone, email, active status).
- **Show All Students**: Paginated display with 10 records per page and intuitive navigation (Next, Previous, Main Menu, Exit).
- **Search Student**: Four search criteria – Roll Number, Name, Department, cGPA.
- **Update Student**: Modify semester, cGPA, phone, email, or active status of any student.
- **Delete Student**: Two deletion modes – Logical (soft-delete) and Actual (permanent removal).
- **Statistics & Reports**: Automatic generation of:
  - General statistics (total, active, inactive students)
  - Students count by department (CS, IT, ME, EE, CE)
  - cGPA distribution (Excellent, Very Good, Good, Accepted)
  - Semester‑wise distribution (1–8)
- **Arrange/Sort**: Five sorting options:
  - Roll Number ascending / descending
  - Name A‑Z
  - cGPA descending
  - Semester ascending
- **Export to TXT**: Saves all records to a delimited text file (`Student.txt`) for external use.
- **Import from TXT**: Reads and merges records from a text file (duplicates ignored).
- **Backup & Restore**: Full data backup and restore using a binary file.
- **Robust Input Validation**: Prevents invalid data entry with friendly error messages and re‑prompts.
- **Automatic Roll Number Generation**: Sequential, starting from 1000 (or max+1 if records exist).
- **Binary File Storage**: All data automatically saved to `Students.data` for persistence between sessions.
- **User‑Friendly Interface**: Colored console output, clear separators, and consistent headers.

---

## 📸 Screenshots

> *Screenshots will be added soon.*  
>  
> *You can place actual images in `screenshots/` folder and reference them here.*  
> Example: `![Main Menu](screenshots/main_menu.png)`

---

## 📁 Project Structure

```

Student-Management-System/
│
├── Student_Managment_System.cpp      (or .txt source provided)
├── Student Management System/        (created automatically at runtime)
│   ├── Students.data                 (binary storage)
│   └── Student.txt                   (export file)
├── README.md
└── screenshots/                      (optional)

```

---

## 🚀 Getting Started

### Prerequisites

- Windows operating system (the code uses `system("cls")` and `system("color")`).
- A C++ compiler supporting **C++17** (e.g., MinGW‑w64, MSVC, TDM‑GCC).
- Basic knowledge of terminal/command prompt.

### Compilation

Using **g++** (MinGW) :

```bash
g++ -std=c++17 -o sms.exe "Student_Managment_System.cpp"
```

Or using MSVC (Developer Command Prompt) :

```cmd
cl /EHsc /std:c++17 Student_Managment_System.cpp /Fe:sms.exe
```

Running the Program

After compilation, execute the program:

```bash
sms.exe
```

The application will automatically create the required folder and binary file on the first run.

---

💻 Usage

1. Launch the program.
2. You will be greeted with the Main Menu displaying 11 options.
3. Enter the number corresponding to your desired operation.
4. Follow the on‑screen prompts and provide the requested information.
5. Use E (or e) to exit the program from any message screen, or M (Main Menu) to return.
6. All changes are automatically saved to the binary file.

---

🔧 Function Modules

Main Menu Options

Option Function
1 Add New Student Record
2 Show All Students (paginated)
3 Search in Students Records
4 Update Student Record
5 Delete Student Record
6 Statistics & Reports
7 Arrange Records
8 Export to TXT File
9 Import from TXT File
10 Backup & Restore
11 Exit

Data Validation

The system enforces strict validation rules:

· Integers: Must be numeric and ≥ 0.
· Names: No digits allowed; alphabetic characters only.
· Department: Must be one of CS, IT, ME, EE, CE.
· Semester: Between 1 and 8 inclusive.
· cGPA: Between 0.0 and 4.0.
· Date of Birth: Day (1‑31), Month (1‑12), Year (1980‑2026).
· Phone: Exactly 9 digits.
· Email: Must contain @.
· Active Status: Boolean (1/0).

If invalid input is detected, the console turns red and prompts for a valid value.

Persistence

· All records are stored in a binary file (Students.data) for fast and compact storage.
· Data is automatically loaded at startup and saved after every modification.
· Export/import functions provide plain‑text interoperability.

---

📊 Data Flow & Storage

The following diagram illustrates how data flows through the system:

```
+---------------------+
|   User Interface    |
+----------+----------+
           |
           v
+----------+----------+
|   Input Validation  |
+----------+----------+
           |
           v
+----------+----------+
|   Core Functions    |<----->  vector<stStudents>  (in memory)
| (Add, Update, etc.) |
+----------+----------+
           |
           v
+----------+----------+
| Binary File I/O     |
+---------------------+
           |
           v
    Students.data
```

---

🧪 Testing

The system has been tested for:

· Normal input scenarios.
· Edge cases (empty lists, duplicate search, invalid formats).
· Numeric boundary values (semester, cGPA, age).
· String handling with mixed case and special characters.
· File I/O robustness (missing files, unexpected format).

To run a quick test: add a few students, export to TXT, then import them back into another instance.

---

🤝 Contributing

Contributions are welcome! If you'd like to improve the project:

1. Fork the repository.
2. Create a new branch: git checkout -b feature/YourFeature
3. Make your changes.
4. Test thoroughly.
5. Commit your changes: git commit -m 'Add some feature'
6. Push to the branch: git push origin feature/YourFeature
7. Open a Pull Request.

Please ensure your code follows the existing style and includes appropriate comments.

---

📝 License

This project is licensed under the MIT License.
See the LICENSE file for details.

---

📧 Contact

Falah Fathel

· GitHub: FALCONZeroX
· Project Repository: Student Management System

Feel free to reach out for any questions or suggestions.
© 2026 FALAH FATHEL. All rights reserved.

---

<p align="center">
  Made with ❤️ and C++
</p>
```
