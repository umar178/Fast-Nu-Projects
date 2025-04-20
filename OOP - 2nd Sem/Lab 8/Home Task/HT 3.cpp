#include <iostream>
using namespace std;

class Patient;

class Doctor {
public:
    void updateMedicalHistory(Patient& p, string newHistory);
    void displayPatient(const Patient& p);
};

class Patient {
private:
    string name;
    int age;
    string medicalHistory;

public:
    Patient(string n, int a) : name(n), age(a), medicalHistory("None") {}
    friend class Doctor;
};

void Doctor::updateMedicalHistory(Patient& p, string newHistory) {
    p.medicalHistory = newHistory;
}

void Doctor::displayPatient(const Patient& p) {
    cout << "Patient: " << p.name << ", Age: " << p.age << ", History: " << p.medicalHistory << endl;
}

int main() {
    Patient p("John", 30);
    Doctor d;

    d.updateMedicalHistory(p, "Diabetes");
    d.displayPatient(p);

    return 0;
}

