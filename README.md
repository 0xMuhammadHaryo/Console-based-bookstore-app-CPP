# 📚 Bookstore Management System (C++)

A console-based bookstore management application built with C++.
This program allows users to manage book data, perform transactions, and generate daily sales reports with file persistence.

---

## 🚀 Features

* 📖 Add, update, and delete book data (CRUD)
* 📋 Display all available books
* 💰 Book purchase transactions
* 📊 Track total sales and revenue
* 🏆 Identify best-selling books
* 💾 Data persistence using file handling (`data_buku.txt`)
* 🧾 Generate daily sales reports (`laporan_harian.txt`)

---

## 🧠 Concepts Implemented

This project demonstrates the use of:

* Structs
* Dynamic Memory Allocation (`new` & `delete`)
* Function Overloading
* Inline Functions
* Template Functions
* File Handling (`ifstream`, `ofstream`)
* Pointer manipulation
* Modular programming with namespace

---

## 🏗️ Project Structure

```bash
.
├── main.cpp
├── data_buku.txt        # (auto-generated / required for data storage)
├── laporan_harian.txt   # (auto-generated report)
└── README.md
```

---

## ▶️ How to Run

### 1. Compile the program

```bash
g++ main.cpp -o bookstore
```

### 2. Run the program

```bash
./bookstore
```

---

## 📌 How It Works

* The program loads book data from `data_buku.txt` at startup
* Users can manage books and perform transactions via menu
* Sales and stock are updated dynamically
* At exit:

  * Data is saved back to `data_buku.txt`
  * A daily report is generated in `laporan_harian.txt`

---

## ⚠️ Notes

* Ensure `data_buku.txt` exists or will be created automatically
* Input must be valid to avoid runtime errors
* This is a console-based application (no GUI)

---

## 🔧 Future Improvements

* Convert to Object-Oriented Programming (OOP)
* Replace raw pointers with `vector`
* Add search & sorting features
* Improve input validation
* Build a GUI version

---

## 👨‍💻 Author

Muhammad Haryo

---

## ⭐ Acknowledgment

This project was created as part of learning fundamental C++ programming concepts and data management.
