# Bank, Student, Task, and Multi-User Banking System

## Overview
This project consists of four separate C++ applications for managing bank accounts, students, tasks, and a multi-user banking system. Each application stores data in a text file for persistence and provides functionalities for adding, displaying, and modifying records.

## Features
### **Bank Account Management System**
- Create a new bank account with an initial deposit
- Display all existing bank accounts
- Data persistence using `accounts.txt`

### **Multi-User Banking System**
- Allows multiple users to create and manage bank accounts
- Supports deposits, withdrawals, and balance inquiries
- User authentication for secure access
- Data persistence using `multi_accounts.txt`

### **Student Management System**
- Add new students with their grades
- Display all students
- Data persistence using `students.txt`

### **Task Management System**
- Add new tasks with a default status of "Pending"
- Mark tasks as "Completed"
- Display all tasks
- Data persistence using `tasks.txt`

## Installation
1. Clone this repository or copy the source files.
2. Compile the C++ files using a C++ compiler (e.g., `g++`).
3. Run the executables.

## Compilation
For Linux/macOS (using g++):
```sh
 g++ bank.cpp -o bank
 g++ multi_user_bank.cpp -o multi_bank
 g++ student.cpp -o student
 g++ task.cpp -o task
```
For Windows (using MinGW):
```sh
 g++ bank.cpp -o bank.exe
 g++ multi_user_bank.cpp -o multi_bank.exe
 g++ student.cpp -o student.exe
 g++ task.cpp -o task.exe
```

## Usage
### **Running the Bank System**
```sh
 ./bank
```
### **Running the Multi-User Banking System**
```sh
 ./multi_bank
```
### **Running the Student System**
```sh
 ./student
```
### **Running the Task System**
```sh
 ./task
```

## File Storage Format
Each system maintains a corresponding text file:
- `accounts.txt` for bank accounts
- `multi_accounts.txt` for multi-user banking
- `students.txt` for student records
- `tasks.txt` for task management

The format for each file follows:
```
<ID>
<Name>
<Additional Information>
```

## Contributions
Feel free to fork and improve the project!

## Licenses
This project is licensed under the MIT License.
