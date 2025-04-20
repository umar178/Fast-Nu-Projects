#include <iostream>
using namespace std;

class Employee;

class HR {
public:
    void updateSalary(Employee& e, float newSalary);
    friend class Manager;
};

class Employee {
private:
    string name;
    float salary;

public:
    Employee(string n, float s) : name(n), salary(s) {}
    friend class HR;
    friend class Manager;
};

class Manager {
public:
    void viewSalary(const Employee& e) {
        cout << "Employee Salary: " << e.salary << endl;
    }
};

void HR::updateSalary(Employee& e, float newSalary) {
    e.salary = newSalary;
}

int main() {
    Employee e("Alice", 50000);
    HR hr;
    Manager m;

    hr.updateSalary(e, 60000);
    m.viewSalary(e);

    return 0;
}

