#include <iostream>
using namespace std;

class Customer {
private:
    static int nextID;
    int customerID;
    string name;

public:
    Customer(string _name) : name(_name), customerID(nextID++) {} 

    void displayCustomer() {
        cout << "Customer ID: " << customerID << " | Name: " << name << endl;
    }

    static void displayNextID() {
        cout << "Next Available Customer ID: " << nextID << endl;
    }
};

int Customer::nextID = 5000;

int main() {
    Customer c1("Alice"), c2("Bob"), c3("Charlie");
    c1.displayCustomer();
    c2.displayCustomer();
    c3.displayCustomer();
    Customer::displayNextID();
    return 0;
}

