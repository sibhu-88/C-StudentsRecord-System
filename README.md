# Student Record Management System

## Overview

The **Student Record Management System** is a console-based application developed in **C** to manage student information using a **Singly Linked List**. The project demonstrates fundamental concepts of **Data Structures**, **Dynamic Memory Allocation**, **File Handling**, and **Modular Programming**.

Student records are stored in memory using a linked list and can be saved to or loaded from a text file.

---

## Features

* Add New Student Record
* Auto Generate Roll Number
* Display All Student Records
* Modify Student Details
* Delete Record by Roll Number
* Delete Record by Student Name
* Sort Records by Student Name (Ascending)
* Sort Records by Percentage (Descending)
* Reverse Display of Student Records
* Save Records to File
* Load Records from File
* Exit with Save Confirmation

---

## Project Structure

```
Student_Record_System/
│
├── header.h
├── main.c
├── menu.c
├── utils.c
├── file.c
├── add.c
├── delete.c
├── modify.c
├── display.c
├── sort.c
├── reverse.c
├── Makefile
├── student.txt
└── README.md
```

---

## Data Structure Used

The project uses a **Singly Linked List**.

```c
typedef struct sdb
{
    int rollno;
    char name[50];
    float percentage;
    struct sdb *next;
} SDB;
```

---

## Functional Modules

### 1. Add Record

* Generates Roll Number automatically.
* Accepts Student Name.
* Accepts Percentage.
* Adds the record to the linked list.

---

### 2. Display Records

Displays all student records in a formatted table.

Example:

```
=================================================================
| Roll No  | Student Name              | Percentage |
=================================================================
| 101      | Prabhu                    | 91.50%     |
| 102      | Rahul                     | 84.75%     |
=================================================================
```

---

### 3. Modify Record

Search Student by:

* Roll Number
* Student Name

Modify:

* Student Name
* Percentage

---

### 4. Delete Record

Delete using:

* Roll Number
* Student Name

Confirmation is requested before deleting.

Example:

```
Delete this record? (Y/N):
```

---

### 5. Sort Records

Sort student records without modifying the original linked list.

Available options:

* Student Name (Ascending)
* Percentage (Descending)

---

### 6. Reverse Display

Displays records in reverse order without changing the linked list.

---

### 7. File Handling

Records are stored in:

```
student.txt
```

Functions:

* Read records from file
* Save records to file

---

## Compilation

Compile the project using:

```bash
make
```

---

## Run

```bash
./student_db
```

or

```bash
make run
```

---

## Clean Object Files

```bash
make clean
```

---

## Rebuild

```bash
make rebuild
```

---

## Sample Menu

```
********************************************************
*      STUDENT RECORD MANAGEMENT SYSTEM                *
********************************************************
* [A] Add New Student Record                           *
* [D] Delete Student Record                            *
* [M] Modify Student Record                            *
* [S] Show Student Records                             *
* [T] Sort Student Records                             *
* [R] Reverse Student Records                          *
* [V] Save Records                                     *
* [E] Exit                                             *
********************************************************
```

---

## Technologies Used

* Programming Language : C
* Operating System : Ubuntu Linux
* Compiler : GCC
* Build Tool : Make
* Data Structure : Singly Linked List
* File Storage : Text File

---

## Learning Outcomes

This project demonstrates practical implementation of:

* Structures
* Pointers
* Dynamic Memory Allocation
* Singly Linked List
* Searching Techniques
* Sorting Algorithms
* File Handling
* Modular Programming
* Makefile
* Command-Line Application Development

---

## Author

**Prabhu**

Embedded Systems Trainer

---

## License

This project is intended for educational and learning purposes.
