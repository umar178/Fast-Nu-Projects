#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
};

class Doctor : public Person {
protected:
    string specialization;

public:
    Doctor(string n, int a, string s) : Person(n, a), specialization(s) {}
};

class Surgeon : public Doctor {
private:
    int surgeryCount;

public:
    Surgeon(string n, int a, string s, int sc) : Doctor(n, a, s), surgeryCount(sc) {}

    void displayDetails() const {
        cout << "=== Surgeon Details ===\nName: " << name << "\nAge: " << age << "\nSpecialization: " << specialization;
        cout << "\nSurgeries Performed: " << surgeryCount << endl;
    }
};

int main() {
    Surgeon s("Dr. John Smith", 45, "Cardiac Surgery", 250);
    s.displayDetails();
    return 0;
}

