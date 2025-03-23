#include <iostream>
using namespace std;

class Person {
protected:
    string name, contactInfo;

public:
    Person(string n, string c) : name(n), contactInfo(c) {}
};

class BankEmployee : virtual public Person {
protected:
    int employeeID;
    string position;

public:
    BankEmployee(string n, string c, int id, string p) : Person(n, c), employeeID(id), position(p) {}
};

class Customer : virtual public Person {
protected:
    int accountNumber;
    double balance;

public:
    Customer(string n, string c, int acc, double bal) : Person(n, c), accountNumber(acc), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient funds!\n";
        else {
            balance -= amount;
            cout << "Withdrawn $" << amount << ". New balance: $" << balance << endl;
        }
    }
};

class BankManager : public BankEmployee, public Customer {
public:
    BankManager(string n, string c, int id, string p, int acc, double bal)
        : Person(n, c), BankEmployee(n, c, id, p), Customer(n, c, acc, bal) {}

    void displayDetails() const {
        cout << "=== Bank Manager Details ===\nName: " << name << "\nContact: " << contactInfo;
        cout << "\nEmployee ID: " << employeeID << "\nPosition: " << position;
        cout << "\nAccount Number (for internal transactions): " << accountNumber << "\nBalance: $" << balance << endl;
    }
};

int main() {
    BankManager bm("Alice Johnson", "alice@email.com", 1001, "Branch Manager", 50001, 10000);
    bm.displayDetails();

    cout << "=== Transactions ===\n";
    bm.deposit(5000);
    bm.withdraw(3000);
    bm.withdraw(15000);

    return 0;
}

