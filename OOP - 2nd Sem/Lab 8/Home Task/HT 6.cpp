#include <iostream>
using namespace std;

class HR;

class Employee {
private:
    string name;
    float salary;
    int workHours;

public:
    Employee(string n, float s, int h) : name(n), salary(s), workHours(h) {}
    friend class HR;
    friend float Payroll(Employee& e);
};

class HR {
public:
    void modify(Employee& e, float newSalary, int newHours) {
        e.salary = newSalary;
        e.workHours = newHours;
    }
};

float Payroll(Employee& e) {
    if (e.workHours > 40) return e.salary + 500;
    else if (e.workHours < 30) return e.salary - 200;
    else return e.salary;
}

int main() {
    Employee e("David", 4000, 35);
    HR hr;
    hr.modify(e, 4500, 45);

    cout << "Final Salary: " << Payroll(e) << endl;
    return 0;
}

