#include <iostream>
using namespace std;

class Student {
public:
    int id;
    string name;
    int grade;

    Student(int _id, string _name, int _grade) : id(_id), name(_name), grade(_grade) {}

    void display() {
        cout << "ID: " << id << " | Name: " << name << " | Grade: " << grade << endl;
    }
};

class Course {
private:
    string title;
    Student* students[3]; 
    int count;

public:
    Course(string _title) : title(_title), count(0) {}

    void addStudent(Student* s) {
        if (count < 3) {
            students[count++] = s;
        }
    }

    void display() {
        cout << "Course: " << title << " - Student List:\n";
        int totalGrade = 0, highestGrade = 0;
        Student* topStudent = NULL;

        for (int i = 0; i < count; i++) {
            students[i]->display();
            totalGrade += students[i]->grade;
            if (students[i]->grade > highestGrade) {
                highestGrade = students[i]->grade;
                topStudent = students[i];
            }
        }

        cout << "Average Grade: " << totalGrade / count << endl;
        if (topStudent) {
            cout << "Top Student: " << topStudent->name << " with " << topStudent->grade << " marks.\n";
        }
    }
};

int main() {
    Student s1(101, "Alice", 85), s2(102, "Bob", 92), s3(103, "Charlie", 78);
    Course dataStructures("Data Structures");

    dataStructures.addStudent(&s1);
    dataStructures.addStudent(&s2);
    dataStructures.addStudent(&s3);
    dataStructures.display();
    return 0;
}

