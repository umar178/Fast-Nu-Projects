#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    double marks;

public:
    Student(string n = "Umar", int r = 240880, double m = 85.5) : name(n), rollNumber(r), marks(m) {
        cout << " Student Registered: " << name << " (Roll# " << rollNumber << ")" << endl;
    }

    ~Student() {
        cout << " Student Profile Deleted: " << name << endl;
    }

    void displayStudentInfo() {
        cout << " Name: " << name << " | Roll Number: " << rollNumber << " | Marks: " << marks << "%" << endl;
    }
};

int main() {
    Student s1;
    Student s2("Akbar", 240680, 86.5);
    s1.displayStudentInfo();
    s2.displayStudentInfo();
    return 0;
}
