#include <iostream>
using namespace std;

int main() {
    int departments;
    cout<<"muhammad Umer Karim / 24k-0880"<<endl;
    cout << "Enter number of departments: ";
    cin >> departments;

    int* students = new int[departments];
    int*** marks = new int**[departments];

    for (int d = 0; d < departments; d++) {
        cout << "\nEnter number of students in department " << d + 1 << ": ";
        cin >> students[d];

        marks[d] = new int*[students[d]];
        for (int s = 0; s < students[d]; s++) {
            marks[d][s] = new int[5];
            cout << " Enter marks for student " << s + 1 << endl;
            for (int sub = 0; sub < 5; sub++) {
            	cout << "Subject "<<sub+1<<":";
                cin >> marks[d][s][sub];
            }
        }
    }

    for (int d = 0; d < departments; d++) {
        int highest = -1, lowest = 101; 
        int sum = 0, count = 0;

        for (int s = 0; s < students[d]; s++) {
            for (int sub = 0; sub < 5; sub++) {
                int mark = marks[d][s][sub];
                if (mark > highest) highest = mark;
                if (mark < lowest) lowest = mark;
                sum += mark;
                count++;
            }
        }

        double avg = (double)sum / count;

        cout << "\nDepartment " << d + 1 << ":\n";
        cout << " Highest Mark = " << highest << "\n";
        cout << " Lowest Mark  = " << lowest << "\n";
        cout << " Average Mark = " << avg << "\n";
    }

    for (int d = 0; d < departments; d++) {
        for (int s = 0; s < students[d]; s++) {
            delete[] marks[d][s];
        }
        delete[] marks[d];
    }
    delete[] marks;
    delete[] students;

    return 0;
}

