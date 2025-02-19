#include <iostream>
using namespace std;

class Battery {
public:
    int capacity;
    string type;
    
    Battery(int cap, string t) : capacity(cap), type(t) {}
};

class Smartphone {
private:
    string brand;
    Battery battery;

public:
    Smartphone(string _brand, int cap, string type) : brand(_brand), battery(cap, type) {}

    void display() {
        cout << "Smartphone Brand: " << brand << endl;
        cout << "Battery: " << battery.capacity << "mAh | Type: " << battery.type << endl;
    }
};

int main() {
    Smartphone phone("Samsung", 5000, "Li-Ion");
    phone.display();
    return 0;
}

