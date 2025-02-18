#include <iostream>
#include <string>
using namespace std;

class EmployeeSalary {
private:
    string name;
    double salary;

public:
    EmployeeSalary(string n, double s) : name(n), salary(s) {}

    void display() const {
        cout << "Employee: " << name << " | Salary: $" << salary << endl;
    }
};

int main() {
    EmployeeSalary employees[] = {
        EmployeeSalary("Ahmed", 50000),
        EmployeeSalary("Sara", 60000),
        EmployeeSalary("John", 55000)
    };

    int numEmployees = sizeof(employees) / sizeof(employees[0]);

    cout << "Employee Salary Records:" << endl;
    for (int i = 0; i < numEmployees; i++) {
        employees[i].display();
    }

    return 0;
}
