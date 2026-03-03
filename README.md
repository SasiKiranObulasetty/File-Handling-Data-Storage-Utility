Student Data Storage Utility
📌 Overview

This project is a low-level file handling and structured data storage utility implemented in C.
It demonstrates binary file operations, buffered disk access optimization, and safe update/delete mechanisms.

🚀 Features

Add student records (binary structured storage)

Display records using buffered block reading

Search records by roll number

Update records in-place using fseek

Delete records using controlled file rewrite strategy

🛠 Technologies Used

C Programming

Standard File I/O (fopen, fread, fwrite, fseek)

Binary File Handling

Linux Build System (Makefile)

📂 File Structure
File-Handling-Utility/
│
├── filehandling.c
├── Makefile
├── README.md
└── students.dat (generated at runtime)
⚙️ Compilation (Linux / WSL)
make
./filehandling

To clean build:

make clean
🧠 System-Level Concepts Demonstrated

Structured binary record storage

Efficient buffered file reading

In-place file modification using file pointer repositioning

Safe record deletion using temporary file rewriting

Memory-aligned struct storage

📊 Why Binary Storage?

Binary format allows:

Fixed-size records

Faster read/write operations

Reduced parsing overhead

Efficient random access

👨‍💻 Author

Sasikiran Obulasetty
B.Tech CSE