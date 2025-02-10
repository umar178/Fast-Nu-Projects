#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor called! Object created." << endl;
    }

    ~MyClass() {
        cout << "Destructor called! Object destroyed." << endl;
    }

    void display() {
        cout << "Hello from MyClass!" << endl;
    }
};

int main() {
    MyClass obj;
    obj.display();
    cout << "Object is now out of scope." << endl;
}

