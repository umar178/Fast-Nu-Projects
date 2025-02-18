#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    int id;

    Employee(string emplame, int empId) : name(emplame), id(empId) {}

    void display() const {
    cout << "Employee ID: " << id << ", Name: " << name << endl;
    }
};

class Department {
private:
    string deptName;
    Employee* employees[10];
    int employeeCount = 0;

public:
    Department(string name) : deptName(name) {}

    void addEmployee(Employee* emp) {
    employees[employeeCount++] = emp;
    }

    void displayDepartment() const {
    cout << "Department: " << deptName << endl << "Employees: " << endl;
    for (int i = 0; i < employeeCount; i++) employees[i]->display();
    }
};

int main() {
    Employee e1("Shaheen Shah Afridi", 10), e2("Muhammad Rizwan", 16),
    e3("Babar Azam", 50);
    Department dept("Software Engineering");

    dept.addEmployee(&e1);
    dept.addEmployee(&e2);
    dept.displayDepartment();

    cout << endl << "Independent Employee:" << endl;
    e3.display();

    return 0;
}
