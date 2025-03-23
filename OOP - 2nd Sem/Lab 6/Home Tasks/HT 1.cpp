#include <iostream>
using namespace std;

class Product {
protected:
    string name, brand;
    double price;

public:
    Product(string n, string b, double p) : name(n), brand(b), price(p) {}

    void displayDetails() const {
        cout << "Product Name: " << name << "\nBrand: " << brand << "\nPrice: $" << price << endl;
    }
};

class ElectronicProduct : public Product {
private:
    int warrantyPeriod;

public:
    ElectronicProduct(string n, string b, double p, int w) : Product(n, b, p), warrantyPeriod(w) {}

    void displayDetails() const {
        Product::displayDetails();
        cout << "Warranty Period: " << warrantyPeriod << " months\n";
    }
};

int main() {
    cout << "=== General Product Details ===\n";
    Product p("Backpack", "Nike", 49.99);
    p.displayDetails();

    cout << "\n=== Electronic Product Details ===\n";
    ElectronicProduct ep("Smartphone", "Samsung", 799.99, 24);
    ep.displayDetails();

    return 0;
}

