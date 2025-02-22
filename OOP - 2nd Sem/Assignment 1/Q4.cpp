#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string pickup;
    string dropoff;
    bool active;
    bool present;

public:
    Student(int _id, string PU, string DO) : id(_id), pickup(PU), dropoff(DO), active(false), present(false) {}

    int getId() const { return id; }
    string getPickup() const { return pickup; }
    string getDropoff() const { return dropoff; }
    bool isActive() const { return active; }
    bool isPresent() const { return present; }

    void showDetails() const {
        cout << "Student ID: " << id << "\nPickup: " << pickup << "\nDropoff: " << dropoff;
        cout << "\nStatus: " << (active ? "Active" : "Inactive") << "\nAttendance: " << (present ? "Present" : "Absent") << endl;
    }

    void payFees() {
        if (!active) {
            active = true;
            cout << "Student " << id << " has paid semester fees.\n";
        } else {
            cout << "Fees already paid for Student " << id << ".\n";
        }
    }

    void tapCard() {
        if (active) {
            present = true;
            cout << "Attendance marked for Student " << id << ".\n";
        } else {
            cout << "Payment required! Student " << id << " cannot mark attendance.\n";
        }
    }
};

class Transport {
private:
    int busNo;
    string* stops;
    int totalStops;
    Student** students;
    int capacity, studentCount = 0;

public:
    Transport(int no, string* stopList, int totalStops, int cap) : busNo(no), totalStops(totalStops), capacity(cap) {
        stops = new string[totalStops];
        for (int i = 0; i < totalStops; i++) {
            stops[i] = stopList[i];
        }

        students = new Student*[capacity];
        for (int i = 0; i < capacity; i++) {
            students[i] = nullptr;
        }
    }

    void registerStudent(Student* s) {
        if (studentCount < capacity) {
            for (int i = 0; i < totalStops; i++) {
                if (s->getPickup() == stops[i]) {
                    students[studentCount] = new Student(*s);
                    studentCount++;
                    cout << "Student " << s->getId() << " registered for bus " << busNo << ".\n";
                    return;
                }
            }
            cout << "Error: Student's pickup location does not match bus stops.\n";
        } else {
            cout << "Error: Bus " << busNo << " is full.\n";
        }
    }

    void showTransportDetails() const {
        cout << "\nBus Number: " << busNo << "\nStops: ";
        for (int i = 0; i < totalStops; i++) {
            cout << stops[i] << (i == totalStops - 1 ? "" : ", ");
        }
        cout << "\nCapacity: " << capacity << "\nRegistered Students: " << studentCount << endl;

        for (int i = 0; i < studentCount; i++) {
            if (students[i] != nullptr) {
                students[i]->showDetails();
                cout << "-----------------\n";
            }
        }
    }

    ~Transport() {
        delete[] stops;
        for (int i = 0; i < studentCount; i++) {
            delete students[i];
        }
        delete[] students;
    }
};

int main() {
    string stopsList[] = {"Stop A", "Stop B", "Stop C", "Stop D"};
    Transport bus1(101, stopsList, 4, 3);

    Student s1(1, "Stop A", "Stop C");
    Student s2(2, "Stop B", "Stop D");
    Student s3(3, "Stop C", "Stop A");
    Student s4(4, "Stop X", "Stop D");  // Invalid stop

    bus1.registerStudent(&s1);
    bus1.registerStudent(&s2);
    bus1.registerStudent(&s3);
    bus1.registerStudent(&s4);  // Should fail due to incorrect pickup stop

    s1.payFees();
    s2.payFees();
    s1.tapCard();
    s2.tapCard();
    s3.tapCard();  // Should fail because fees aren't paid

    bus1.showTransportDetails();

    return 0;
}

