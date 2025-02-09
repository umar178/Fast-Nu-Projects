#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    string productName;
    double price;
    int stock;
    double discount;

public:
    Product(string name, double p, int s, double d) {
        productName = name;
        price = p;
        stock = s;
        discount = d;
    }

    void displayProduct() {
        cout << "\nProduct Name: " << productName 
             << "\nPrice: $" << price 
             << "\nStock: " << stock 
             << "\nDiscount: " << discount << "%\n";
    }

    void applyDiscount() {
        double newPrice = price - (price * (discount / 100));
        cout << "Price after discount: $" << newPrice << "\n";
    }

    void updateStock(int quantity) {
        if (quantity <= stock) {
            stock -= quantity;
            cout << quantity << " item(s) sold. Remaining stock: " << stock << "\n";
        } else {
            cout << "Not enough stock available.\n";
        }
    }

    string getProductName() {
        return productName;
    }
};

int main() {
    vector<Product> catalog;
    catalog.push_back(Product("Laptop", 1000, 10, 10));
    catalog.push_back(Product("Phone", 500, 20, 5));
    catalog.push_back(Product("Headphones", 100, 30, 15));

    int choice;
    do {
        cout << "\nProduct Catalog Menu\n";
        cout << "1. View All Products\n2. Apply Discount\n3. Update Stock\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < catalog.size(); i++) {
                catalog[i].displayProduct();
            }
        } 
        else if (choice == 2) {
            cin.ignore();
            string name;
            cout << "Enter product name: ";
            getline(cin, name);
            bool found = false;
            for (int i = 0; i < catalog.size(); i++) {
                if (catalog[i].getProductName() == name) {
                    catalog[i].applyDiscount();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Product not found.\n";
        } 
        else if (choice == 3) {
            cin.ignore();
            string name;
            int quantity;
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter quantity sold: ";
            cin >> quantity;
            bool found = false;
            for (int i = 0; i < catalog.size(); i++) {
                if (catalog[i].getProductName() == name) {
                    catalog[i].updateStock(quantity);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Product not found.\n";
        } 
        else if (choice == 4) {
            cout << "Exiting Product Catalog...\n";
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

