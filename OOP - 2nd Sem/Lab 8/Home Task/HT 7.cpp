#include <iostream>
using namespace std;

class InventoryManager;

class Product {
private:
    string productName;
    float price;
    int stockQuantity;

public:
    Product(string n, float p, int q) : productName(n), price(p), stockQuantity(q) {}
    friend class InventoryManager;
    friend void applyDiscount(Product& p, float percentage);
};

class InventoryManager {
public:
    void display(const Product& p) {
        cout << "Product: " << p.productName << ", Price: " << p.price << ", Stock: " << p.stockQuantity << endl;
    }

    void updateStock(Product& p, int newQty) {
        p.stockQuantity = newQty;
    }
};

void applyDiscount(Product& p, float percent) {
    p.price -= (p.price * percent / 100);
}

int main() {
    Product p("Laptop", 1000, 10);
    InventoryManager im;

    im.display(p);
    applyDiscount(p, 10);  
    im.updateStock(p, 8);

    im.display(p);
    return 0;
}

