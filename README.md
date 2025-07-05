# 🏥 Hospital Management System (C++ Project)

This is a simple **Hospital Management System** written in C++ for managing patients in a small hospital. It was developed as a final project to practice C++ programming fundamentals and file handling.

## 📌 Features

- Assign patients to rooms
- Discharge patients
- Search patients by name and ID
- Generate bills based on stay duration
- Update patient data (name, room, or stay)
- Save and load patient data using binary files
- Display all currently admitted patients

## 🛠️ Technologies Used

- C++ (with `struct`, arrays, file handling, and basic I/O)
- Binary file operations using `fstream`

## 🧩 Project Structure

- **Struct `Patient`**: Represents each patient with ID, name, room info, and billing.
- **Patient Array**: Supports up to 50 patients in memory.
- **Menu Interface**: Console-based navigation for different operations.
- **Data Persistence**: Saves and reads data from `Hospital_Management_System.dat`.

## 📦 How to Run

1. Compile the file using a C++ compiler:
   ```bash
   g++ -o hospital final\ project\ hospital.cpp
