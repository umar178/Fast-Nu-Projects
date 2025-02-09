#include <iostream>
#include <vector>
using namespace std;

class Patient {
private:
    string name;
    int age;
    string disease;
    int roomNumber;

public:
    Patient(string n, int a, string d, int r) {
        name = n;
        age = a;
        disease = d;
        roomNumber = r;
    }

    void displayPatient() {
        cout << "\nName: " << name 
             << "\nAge: " << age 
             << "\nDisease: " << disease 
             << "\nRoom Number: " << roomNumber << "\n";
    }

    void updateDetails() {
        cout << "Enter new age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter new disease: ";
        getline(cin, disease);
        cout << "Enter new room number: ";
        cin >> roomNumber;
        cout << "Patient details updated successfully.\n";
    }

    string getPatientName() {
        return name;
    }
};

int main() {
    vector<Patient> hospital;
    int choice;

    do {
        cout << "\nHospital Management Menu\n";
        cout << "1. Add Patient\n2. Update Patient Details\n3. Display All Patients\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            string name, disease;
            int age, roomNumber;
            cout << "Enter patient name: ";
            getline(cin, name);
            cout << "Enter age: ";
            cin >> age;
            cin.ignore();
            cout << "Enter disease: ";
            getline(cin, disease);
            cout << "Enter room number: ";
            cin >> roomNumber;
            hospital.push_back(Patient(name, age, disease, roomNumber));
            cout << "Patient added successfully!\n";
        } 
        else if (choice == 2) {
            cin.ignore();
            string name;
            cout << "Enter patient name to update: ";
            getline(cin, name);
            bool found = false;
            for (int i = 0; i < hospital.size(); i++) {
                if (hospital[i].getPatientName() == name) {
                    hospital[i].updateDetails();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Patient not found.\n";
        } 
        else if (choice == 3) {
            if (hospital.empty()) cout << "No patients available.\n";
            else {
                for (int i = 0; i < hospital.size(); i++) {
                    hospital[i].displayPatient();
                }
            }
        } 
        else if (choice == 4) {
            cout << "Exiting Hospital Management System...\n";
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

