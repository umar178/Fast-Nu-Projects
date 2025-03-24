#include <iostream>
using namespace std;

class Teacher;

class Student {
private:
    string name;
    double grades[3];

public:
    Student(string n, double g1, double g2, double g3) : name(n) {
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }

    friend class Teacher;
    friend double calculateAverageGrade(const Student& student);
};

double calculateAverageGrade(const Student& student) {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += student.grades[i];
    }
    return sum / 3;
}

class Teacher {
public:
    void updateGrade(Student& student, int index, double newGrade) {
        if (index >= 0 && index < 3) {
            student.grades[index] = newGrade;
            cout << "Grade updated!" << endl;
        } else {
            cout << "Invalid grade index!" << endl;
        }
    }

    void viewGrades(const Student& student) {
        cout << "Grades for " << student.name << ":" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Grade " << i + 1 << ": " << student.grades[i] << endl;
        }
    }
};

int main() {
    Student student("Abdullah", 85.0, 90.0, 78.0);
    Teacher teacher;

    teacher.viewGrades(student);
    teacher.updateGrade(student, 1, 95.0);
    teacher.viewGrades(student);

    double average = calculateAverageGrade(student);
    cout << "Average Grade: " << average << endl;

    return 0;
}
