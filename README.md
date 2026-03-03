## 📌 Overview

This project is a **low-level file handling and structured data storage utility** implemented in C.  
It demonstrates binary file operations, buffered disk access optimization, and safe update/delete mechanisms using controlled file rewriting strategies.
The system stores student records in a binary `.dat` file using structured storage for efficient retrieval and modification.

---

## 🚀 Features

- Add student records (binary structured storage)
- Display records using buffered block reading
- Search records by roll number
- Update records in-place using `fseek`
- Delete records using controlled file rewrite strategy
- Error handling for file operations

---

## 🛠 Technologies Used

- **C Programming**
- Standard File I/O:
  - `fopen`
  - `fread`
  - `fwrite`
  - `fseek`
  - `remove`
  - `rename`
- Binary File Handling
- Linux Build System (Makefile)

---

## 📂 Project Structure

```

File-Handling-Data-Storage-Utility/
│
├── filehandling.c
├── Makefile
├── README.md
└── students.dat   (Generated at runtime)

````

---

## ⚙️ Compilation & Execution (Linux / WSL Recommended)

### Compile

```bash
make
````

### Run

```bash
./filehandling
```

### Clean Build

```bash
make clean
```

---

## 🧠 System-Level Concepts Demonstrated

* Structured binary record storage using `struct`
* Efficient buffered file reading (block-based `fread`)
* In-place record modification using file pointer repositioning (`fseek`)
* Safe record deletion using temporary file rewrite strategy
* Understanding of memory-aligned struct storage
* Controlled disk I/O to minimize redundant access

---

## 📊 Why Binary Storage?

Binary storage enables:

* Fixed-size records
* Faster read/write operations
* Reduced parsing overhead
* Efficient random access
* Direct memory-to-disk structure mapping

---

## 🎯 Learning Outcomes

* Practical understanding of low-level file handling
* Implementation of CRUD operations without using databases
* Safe and efficient data manipulation in persistent storage
* Real-world system programming concepts

---

## 👨‍💻 Author

Sasikiran Obulasetty
B.Tech CSE

 profile now 🚀
```
