#include <iostream>
using namespace std;

class Product {
private:
    string name;
    double price;

public:
    Product() {
    name = "Unknown";
    price = 0.01;
    }

    Product(string name, double price) {
    this->name = name;
    this->price = price;
    cout << endl << "Product added: " << name << " - $" << price << endl;
    }

    void updatePrice(double newPrice) {
    price = newPrice;
    cout << "Updated price of " << name << " to $" << price << endl;
    }

    void display() {
    cout << endl << "Product: " << name << ", Price: $" << price << endl;
    }
};

int main() {
    Product defaultProduct;
    defaultProduct.display();

    Product lastRef("Item", 10.0);
    lastRef.updatePrice(15.0);
    lastRef.display();
}
