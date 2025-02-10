#include <iostream>
using namespace std;

class Example {
private:
    int* data;
    int size;

public:
    Example() : data(NULL), size(0) {
        cout << "Default Constructor called." << endl;
    }

    Example(int s, int value) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = value;
        }
        cout << "Parameterized Constructor called with size " << size << " and value " << value << endl;
    }

    Example(const Example& other) : size(other.size) {
        data = other.data;
        cout << "Shallow Copy Constructor called." << endl;
    }

    Example(const Example& other, bool deepCopy) : size(other.size) {
        if (deepCopy) {
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
            cout << "Deep Copy Constructor called." << endl;
        } else {
            data = other.data;
            cout << "Shallow Copy Constructor called." << endl;
        }
    }

    ~Example() {
        if (data != NULL) {
            cout << "Destructor called for data with size " << size << endl;
            delete[] data;
        } else {
            cout << "Destructor called for empty object." << endl;
        }
    }

    void display() const {
        cout << "Data: ";
        if (data != NULL) {
            for (int i = 0; i < size; ++i) {
                cout << data[i] << " ";
            }
        } else {
            cout << "No data";
        }
        cout << endl;
    }
};

int main() {
    Example obj1;
    obj1.display();

    Example obj2(5, 10);
    obj2.display();

    Example obj3 = obj2;
    obj3.display();

    Example obj4(obj2, true);
    obj4.display();

    return 0;
}

