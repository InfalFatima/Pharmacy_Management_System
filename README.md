# Pharmacy_Management_System
A simple console-based Pharmacy Management System developed in C++ that allows users to manage medicine inventory, including adding, searching, viewing, and selling medicines. Designed as a beginner-level project for educational purposes.

## Features

- 📦 **View Stock Report** – Displays available medicines with quantities and prices.
- ➕ **Add New Medicine** – Add new items or update existing medicine stock.
- 🔍 **Search Medicine** – Search by medicine code or name.
- 💰 **Sell Medicine** – Process sales, update stock, and generate a bill.

## Technologies Used

- **Language**: C++
- **Compiler**: GCC / Dev-C++ 5.11
- **File I/O**: Text file-based storage (`stock.txt`)

## Project Structure

```
PharmacyManagementSystem/
├── main.cpp             # Main source code
├── stock.txt            # Inventory database (text-based)
├── main.o               # Object file (auto-generated)
├── main.exe             # Executable (auto-generated)
```
## Sample `stock.txt` Format

```
M001 Paracetamol 48 1.5
M002 Aspirin 100 0.8
M003 Ibuprofen 75 2
...
```

Each line contains:
```
<MedicineCode> <Name> <Quantity> <Price>
```

## Author

Created by Infal Fatima  
Developed as part of a **1st Semester C++ Programming Fundamentals Project**.  

## License

This project is licensed for educational and personal use. No commercial use allowed without permission.
