#include <iostream>
using namespace std;

class Product {
private:
    static int productCount;

public:
    Product() {
        productCount++;
    }
    static void displayProductCount() {
        cout << "Total Products Created: " << productCount << endl;
    }
};

int Product::productCount = 0;

int main() {
    Product p1, p2, p3;
    Product::displayProductCount();
    return 0;
}
