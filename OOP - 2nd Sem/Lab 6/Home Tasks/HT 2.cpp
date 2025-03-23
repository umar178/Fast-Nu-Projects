#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double salary;

public:
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {}

    void displayDetails() const {
        cout << "Employee Name: " << name << "\nEmployee ID: " << id << "\nBase Salary: $" << salary << endl;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string n, int i, double s, double b) : Employee(n, i, s), bonus(b) {}

    void displayDetails() const {
        Employee::displayDetails();
        cout << "Bonus: $" << bonus << "\nTotal Salary: $" << (salary + bonus) << endl;
    }
};

int main() {
    cout << "=== Employee Details ===\n";
    Employee e("Alice Johnson", 101, 50000);
    e.displayDetails();

    cout << "\n=== Manager Details ===\n";
    Manager m("Bob Smith", 102, 75000, 10000);
    m.displayDetails();

    return 0;
}

