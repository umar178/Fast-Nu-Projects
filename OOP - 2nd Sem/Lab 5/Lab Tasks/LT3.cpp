#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    string name;
    int age;
    string medicalCondition;

public:
    Patient(string n, int a, string m) : name(n), age(a), medicalCondition(m) {}

    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Condition: " << medicalCondition << endl;
    }
};

class Hospital {
private:
    Patient* patients[10];
    int patientCount;

public:
    Hospital() : patientCount(0) {}

    void addPatient(Patient* p) {
        patients[patientCount++] = p;
    }

    void displayPatients() const {
        cout << "Hospital Patient Records:" << endl;
        for (int i = 0; i < patientCount; i++) {
            patients[i]->display();
        }
    }
};

int main() {
    Patient p1("Alice", 30, "Flu");
    Patient p2("Bob", 45, "Diabetes");
    Patient p3("Charlie", 50, "High Blood Pressure");

    Hospital hospital;
    hospital.addPatient(&p1);
    hospital.addPatient(&p2);
    hospital.addPatient(&p3);

    hospital.displayPatients();

    return 0;
}
