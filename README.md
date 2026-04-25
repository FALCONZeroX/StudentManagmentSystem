# 📚 Student Management System

A robust and user-friendly **console-based** Student Records Management System built with **C++**. It provides full CRUD operations, advanced search, statistics, sorting, import/export, and backup functionality. All data is stored locally in binary files for persistence, with the ability to export/import in plain text format.

![C++](https://img.shields.io/badge/language-C%2B%2B-blue)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey)
![License](https://img.shields.io/badge/license-MIT-green)

---

## ✨ Key Features

- **Add New Student**  
  Automatically assigns the next sequential roll number, validates all inputs (names, department, cGPA, semester, email, phone, date of birth, and active status).

- **Show All Students**  
  Paginated display with 10 records per page, showing full details in a clean table. Supports next/previous navigation.

- **Search Records**  
  Search by **Roll Number**, **First Name**, **Department**, or **cGPA**. Displays matching records with export‑style formatting.

- **Update Student**  
  Modify only the fields you need: Semester, cGPA, Phone Number, Email, or Status. Confirmation prompt before saving changes.

- **Delete Student**  
  Two deletion modes: **Logical Delete** (marks as inactive) or **Actual Delete** (removes permanently).

- **Statistics & Reports**  
  Generates on‑screen analytics:  
  - Total, Active, Inactive students  
  - Breakdown by Department (IT, CS, ME, EE, CE)  
  - cGPA distribution (Excellent, Very Good, Good, Accepted)  
  - Semester‑wise distribution (1–8)

- **Arrange / Sort Records**  
  Sort according to:  
  - Roll Number (Ascending / Descending)  
  - First Name (A‑Z)  
  - cGPA (Descending)  
  - Semester (Ascending)  
  Changes are saved immediately after confirmation.

- **Export to TXT File**  
  Exports all records to a delimited text file (`-` as separator) for external use or backup.

- **Import from TXT File**  
  Reads a delimited text file and adds only new records (duplicate roll numbers are skipped). Merged data is saved back to the binary database.

- **Backup & Restore**  
  - **Backup**: manually saves the current in‑memory data to the binary file.  
  - **Restore**: reloads data from the binary file, discarding any unsaved changes.

- **Persistent Local Storage**  
  All student records are stored in a binary file (`Students.data`) inside a dedicated folder. The system automatically loads data on startup.

- **Input Validation & Error Handling**  
  Every user input is validated – from integers and floats to date components, email format, and department codes. Clear error messages guide the user.

- **Professional Console UI**  
  Color‑coded headings, consistent separators, and immediate feedback messages (success, error, cancel) make navigation intuitive.

---

## 🛠 Technologies Used

- **Language**: C++ (standard library only)
- **Standard Template Library (STL)**: `vector`, `algorithm`, `stringstream`
- **File I/O**: `fstream` for binary and text file handling
- **Formatting**: `iomanip` for tabular display
- **No external dependencies** – compiles on any modern C++ compiler.

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler that supports C++11 or later (e.g., `g++`, `clang++`, MSVC)
- (Optional) Git to clone the repository

### Folder Setup

The program expects a folder named `Student Management System` in the **same directory** as the executable. This folder will contain the persistent data files.

You can create it manually:
```bash
mkdir "Student Management System"
