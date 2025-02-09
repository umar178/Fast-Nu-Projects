#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int rollNumber, marks[5], totalMarks;
    float percentage;
    char grade;

    void inputDetails() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter marks for 5 subjects: ";
        totalMarks = 0;
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
            totalMarks += marks[i];
        }
        calculateGrade();
    }

    void calculateGrade() {
        percentage = totalMarks / 5.0;
        if (percentage >= 90) grade = 'A';
        else if (percentage >= 75) grade = 'B';
        else if (percentage >= 50) grade = 'C';
        else grade = 'F';
    }

    void displayReportCard() {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber 
             << "\nTotal Marks: " << totalMarks << "\nPercentage: " << percentage 
             << "\nGrade: " << grade << "\n";
    }
};

int main() {
    Student student;
    student.inputDetails();
    student.displayReportCard();
    return 0;
}

