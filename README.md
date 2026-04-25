```markdown
# 🎓 Student Management System

A comprehensive, console-based **Student Records Management System** built with **C++**, designed to efficiently handle all CRUD operations (Create, Read, Update, Delete) alongside advanced data management features. The application leverages object-oriented principles, file handling, and local binary storage to ensure data persistence and performance.

![C++](https://img.shields.io/badge/C%2B%2B-11-blue)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Console-lightgrey)
![License](https://img.shields.io/badge/License-MIT-green)
![Version](https://img.shields.io/badge/Version-1.0-brightgreen)
![Author](https://img.shields.io/badge/Author-Falah%20Fathel-orange)

---

## 📸 Banner

```

```

---

## 📋 Table of Contents

- [🎯 Key Features](#-key-features)
- [🛠️ System Architecture](#️-system-architecture)
- [💻 Installation & Setup](#-installation--setup)
- [🚀 Usage Guide](#-usage-guide)
  - [Main Menu Navigation](#main-menu-navigation)
  - [Operations Overview](#operations-overview)
- [📂 Data Management](#-data-management)
  - [Binary Storage (Local)](#binary-storage-local)
  - [TXT Export / Import](#txt-export--import)
- [🔍 Search & Filtering](#-search--filtering)
- [📊 Statistics & Reports](#-statistics--reports)
- [🔄 Arrange & Sort](#-arrange--sort)
- [💾 Backup & Restore](#-backup--restore)
- [⚙️ Input Validation](#️-input-validation)
- [🧱 Code Structure](#-code-structure)
- [🌟 Future Enhancements](#-future-enhancements)
- [📄 License & Credits](#-license--credits)

---

## 🎯 Key Features

| Feature | Description |
|--------|-------------|
| **Add New Student** | Full record creation with auto-incremented Roll Number. |
| **Show All Students** | Paginated view (10 per page) with navigation. |
| **Search Records** | Search by Roll Number, Name, Department, or cGPA. |
| **Update Records** | Modify Semester, cGPA, Phone, Email, or Status. |
| **Delete Records** | Logical (soft) and Actual (hard) deletion. |
| **Statistics Dashboard** | Summary reports by Department, cGPA ranges, Semester, and Active/Inactive counts. |
| **Arrange / Sort** | Sort by Roll No (Asc/Desc), Name, cGPA, Semester. |
| **Export to TXT** | Delimiter-based export (default `-`) for external use. |
| **Import from TXT** | Read structured text files with automatic duplicate detection. |
| **Backup & Restore** | Backup all data to binary file or restore from the last saved state. |
| **Data Validation** | Robust input checks for all fields (numeric ranges, name characters, email format, etc.). |
| **Binary Persistence** | All data stored locally in `Students.data` for fast read/write cycles. |

---

## 🛠️ System Architecture

The system follows a **modular, function-oriented design** using core C++ constructs:

- **Struct `stStudents`** – Defines the student entity with 10 fields.
- **Vector `<stStudents>`** – Dynamic array holding all records in memory.
- **Binary File I/O** – `Import_From_Binary_File()` / `Export_To_Binary()` ensure data is saved locally and survives program restarts.
- **CRUD + Utility Functions** – Clean separation of main operations, validation routines, formatting helpers, and sorting comparators.

---

## 💻 Installation & Setup

> **Prerequisites:**  
> - C++ Compiler (MinGW, MSVC, or GCC)  
> - Windows Console (uses `system("cls")`, `system("color")`)

### Steps

1. **Clone the repository:**
   ```bash
   git clone https://github.com/FALCONZeroX/Student-Management-System.git
   cd Student-Management-System
```

1. Compile the code:
   ```bash
   g++ -std=c++11 main.cpp -o StudentManagement.exe
   ```
2. Run the program:
   ```bash
   ./StudentManagement.exe
   ```
3. Ensure the data folder exists:
      The program expects a folder named Student Management System in the same directory to store internal binary and exported files.

---

🚀 Usage Guide

Main Menu Navigation

When launched, the interactive console menu guides you through 11 options:

```
[1] Add New Student Record
[2] Show All Students
[3] Search in Students Records
[4] Update Student Record
[5] Delete Student Record
[6] Statistics & Reports
[7] Arrange Records
[8] Export to TXT File
[9] Import from TXT File
[10] Backup & Restore
[11] Exit
```

Operations Overview

1. Add New Student

· Automatically assigns the next sequential Roll Number.
· Input fields:
  · First Name / Last Name (letters only)
  · Department (IT, CS, ME, EE, CE)
  · Semester (1–8)
  · cGPA (0.0 – 4.0)
  · Date of Birth (DD/MM/YYYY with validation)
  · Phone Number (exactly 9 digits)
  · Email (must contain @)
  · Active Status (1 = Active, 0 = Inactive)
· After successful addition, data is saved automatically to the binary file.

2. Show All Students

· Displays records in a neatly formatted table.
· Pagination with Next (N), Previous (P), Main Menu (M), Exit (E).

3. Search

· Options:
  · By Roll Number: exact match.
  · By Name: case-insensitive comparison on first name.
  · By Department: exact department code.
  · By cGPA: exact float match.
· Prints matching student(s) with full detail header.

4. Update

· Search by Roll Number.
· Modify one field at a time (Semester, cGPA, Phone, Email, Status).
· Confirmation prompt before applying changes.
· Updated record is written back to binary storage.

5. Delete

· Search by Roll Number or Full Name.
· Two deletion modes:
  · Logical Delete: sets Is_Active = false (record remains but marked inactive).
  · Actual Delete: permanently removes record from the vector and file.

---

📂 Data Management

Binary Storage (Local)

· File: Student Management System/Students.data
· Format: Raw stStudents structs written sequentially.
· On Startup: All records are loaded from this file into the vector.
· On Every CRUD Operation: The entire vector is written back to ensure consistency.

TXT Export / Import

· Export:
    Creates Student Management System/Student.txt.
    Fields are separated by a delimiter (default -).
    Example line:
    1001-John-Doe-IT-3-3.5-01/01/2000-123456789-john@mail.com-1
· Import:
    Parses the same delimiter-based format.
    Automatically skips records with duplicate Roll Numbers.
    After import, data is merged and saved to binary.

---

🔍 Search & Filtering

The search engine supports case-insensitive name matching and exact field comparisons. This makes it easy to quickly locate records even when only partial information is known.

Search Type Method Used
Roll Number int equality
Name Convert_To_Lower() + string compare
Department strcmp() exact match
cGPA float direct comparison

---

📊 Statistics & Reports

The Statistics & Reports option provides a real-time dashboard divided into four sections:

1. General Statistics
   · Total students
   · Active / Inactive counts
2. Department-wise Distribution
   · Count per department (IT, CS, ME, EE, CE)
3. cGPA Distribution
   · Excellent (3.5–4.0)
   · Very Good (3.0–3.49)
   · Good (2.5–2.99)
   · Accepted (< 2.5)
4. Semester-wise Distribution
   · Count of students enrolled in each semester (1 to 8)

---

🔄 Arrange & Sort

Sorting is done in-memory using std::sort with custom comparator functions, then the sorted vector is persisted to binary.

Option Sort Logic
Roll No (Ascending) s1.RollNumber < s2.RollNumber
Roll No (Descending) s1.RollNumber > s2.RollNumber
Name (A–Z) First_Name string comparison
cGPA (Descending) s1.cGPA > s2.cGPA
Semester (Ascending) s1.Semester < s2.Semester

A confirmation prompt prevents accidental sorting.

---

💾 Backup & Restore

· Backup: Rewrites the current in-memory state to the binary file (full overwrite).
· Restore: Reloads all data from the existing binary file, discarding any unsaved in-memory changes.

This acts as a snapshot system for the database.

---

⚙️ Input Validation

All user inputs are rigorously validated to prevent crashes and logical errors.

Input Type Validation Rules
Integers cin.fail() check, must be ≥ 0
Names Reject if any digit is present
Department Must be one of IT, CS, ME, EE, CE
Semester Range 1–8
cGPA Range 0.0 – 4.0
Date (Day) 1–31
Date (Month) 1–12
Date (Year) 1980 – 2026
Phone Exactly 9 characters
Email Must contain @
Boolean (Status) 0 or 1

Errors are highlighted via system("color 40") (red background).

---

🧱 Code Structure

```
├── main.cpp
│   ├── struct stStudents
│   ├── Function Prototypes (50+ functions)
│   │
│   ├── main()
│   │   └── Import_From_Binary_File()
│   │   └── Main_Menu()
│   │
│   ├── CRUD Main Functions
│   │   ├── Add_New_Student()
│   │   ├── Show_All_Students()
│   │   ├── Search_Student()
│   │   ├── Update_Student()
│   │   ├── Delete_Student()
│   │   ├── Statistics_And_Reports()
│   │   ├── Arrange_Students()
│   │   ├── Export_To_TXT_File()
│   │   ├── Import_From_TXT_File()
│   │   └── Backup_And_Restore()
│   │
│   ├── Reading & Verifying Functions
│   │   ├── Verify_Integers()
│   │   ├── Verify_Name()
│   │   ├── Verify_Department()
│   │   ├── Verify_Semester()
│   │   ├── Verify_cGPA()
│   │   ├── Verify_Date() / verify_Day / verify_Month / verify_Year
│   │   ├── Verify_Phone()
│   │   ├── Verify_Email()
│   │   └── Verify_Is_Active()
│   │
│   ├── Local Storage Functions
│   │   ├── Import_From_Binary_File()
│   │   └── Export_To_Binary()
│   │
│   ├── UI/UX Helpers
│   │   ├── Header()
│   │   ├── Message()
│   │   ├── Print_Student_Row()
│   │   ├── Print_Student_Header()
│   │   ├── Confirm_Message()
│   │   └── Print_Boolean_as_String()
│   │
│   ├── Sorting Comparators
│   │   ├── Compare_Roll_Ascending()
│   │   ├── Compare_Roll_Descending()
│   │   ├── Compare_Name()
│   │   ├── Compare_cGPA()
│   │   └── Compare_Semester_Ascending()
│   │
│   └── General Utilities
│       ├── Convert_To_Lower()
│       ├── Clear_Buffer()
│       ├── Exist_Student()
│       ├── Find_Student()
│       └── get_next_roll()
```

---

🌟 Future Enhancements

Planned features for upcoming versions:

· MySQL/SQLite Integration – Replace binary file with a relational database.
· GUI Version – Qt or .NET based graphical interface.
· Password Protection – Multi-user authentication.
· Advanced Filtering – Range‑based cGPA and date filters.
· Logging System – Track every create/update/delete operation.
· CSV Support – Export/import in .csv format in addition to custom delimiter.
· Multi‑language Support – English / Arabic.
· Auto‑backup Scheduling – Periodic automatic snapshots.

---

📄 License & Credits

Author: Falah Fathel
GitHub: FALCONZeroX
Year: 2026
Language: C++ (Standard 11)

This project is open-source and available under the MIT License.
Feel free to fork, modify, and contribute.

```
© 2026 Falah Fathel. All Rights Reserved.
```

```
