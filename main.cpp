#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function prototypes
void displayStock();
void addMedicine();
void searchMedicine();
void sellMedicine();

int main() {
    int choice;

    do {
        cout << "\n>>> Pharmacy Management System <<<\n";
        cout << "1. View Stock Report\n";
        cout << "2. Add New Medicine\n";
        cout << "3. Search Medicine\n";
        cout << "4. Sell Medicine\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayStock();
                break;
            case 2:
                addMedicine();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                sellMedicine();
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to display stock
void displayStock() {
    ifstream file("stock.txt");
    if (!file) {
        cout << "Error: Could not open stock file! Make sure 'stock.txt' is in the same directory as the program.\n";
        return;
    }

    string code, name;
    int quantity;
    double price;

    cout << "\nCode\tName\t\tQuantity\tPrice\n";
    cout << "------------------------------------------\n";

    while (file >> code >> name >> quantity >> price) {
        cout << left << setw(8) << code << setw(16) << name
             << setw(12) << quantity << setw(8) << price << "\n";
    }

    file.close();
}

// Function to add or update medicine
void addMedicine() {
    ifstream file("stock.txt");
    ofstream tempFile("temp.txt");

    string code, name, newCode, newName;
    int quantity, newQuantity;
    double price, newPrice;
    bool found = false;

    cout << "Enter medicine code: ";
    cin >> newCode;
    cout << "Enter medicine name: ";
    cin >> newName;
    cout << "Enter quantity: ";
    cin >> newQuantity;
    cout << "Enter price: ";
    cin >> newPrice;

    while (file >> code >> name >> quantity >> price) {
        if (code == newCode) {
            quantity += newQuantity; // Update quantity
            found = true;
        }
        tempFile << code << " " << name << " " << quantity << " " << price << "\n";
    }

    if (!found) {
        tempFile << newCode << " " << newName << " " << newQuantity << " " << newPrice << "\n";
    }

    file.close();
    tempFile.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (found) {
        cout << "Medicine updated successfully!\n";
    } else {
        cout << "New medicine added successfully!\n";
    }
}

// Function to search for a medicine
void searchMedicine() {
    ifstream file("stock.txt");
    if (!file) {
        cout << "Error: Could not open stock file! Make sure 'stock.txt' is in the same directory as the program.\n";
        return;
    }

    string code, name, searchQuery;
    int quantity;
    double price;
    bool found = false;

    cout << "Enter medicine code or name to search: ";
    cin >> searchQuery;

    while (file >> code >> name >> quantity >> price) {
        if (code == searchQuery || name == searchQuery) {
            cout << "\nMedicine Found:\n";
            cout << "Code: " << code << "\n";
            cout << "Name: " << name << "\n";
            cout << "Quantity: " << quantity << "\n";
            cout << "Price: " << price << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Medicine not found!\n";
    }

    file.close();
}

// Function to sell medicine
void sellMedicine() {
    ifstream file("stock.txt");
    ofstream tempFile("temp.txt");

    string code, name, sellCode;
    int quantity, sellQuantity;
    double price, totalBill = 0.0;
    bool found = false;

    cout << "Enter medicine code to sell: ";
    cin >> sellCode;
    cout << "Enter quantity to sell: ";
    cin >> sellQuantity;

    while (file >> code >> name >> quantity >> price) {
        if (code == sellCode) {
            found = true;
            if (quantity >= sellQuantity) {
                quantity -= sellQuantity;
                totalBill = sellQuantity * price;
                cout << "Medicine sold successfully!\n";
                cout << "Total Bill: $" << totalBill << "\n";
            } else {
                cout << "Not enough stock available!\n";
            }
        }
        tempFile << code << " " << name << " " << quantity << " " << price << "\n";
    }

    if (!found) {
        cout << "Medicine not found!\n";
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("stock.txt");
        rename("temp.txt", "stock.txt");
    }
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



