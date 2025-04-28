#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;
};

void writeToFile() {
    ofstream outFile("students.txt", ios::app);
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cin.ignore(); 
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;

    if (outFile.is_open()) {
        outFile << s.rollNo << "," << s.name << "," << s.marks << endl;
        outFile.close();
        cout << "Student data saved successfully!" << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

void readFromFile() {
    ifstream inFile("students.txt");
    string line;
    cout << "\n--- Student Records ---\n";
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student Record\n";
        cout << "2. View All Records\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: 
                writeToFile();
                break;
            case 2: 
                readFromFile();
                break;
            case 3: 
                cout << "Exiting...\n";
                break;
            default: 
                cout << "Invalid choice! \n";
        }
    } while (choice != 3);

    return 0;
}
