#include <iostream>
using namespace std;

class Person {
protected:
    bool active;
    bool present;

public:
    int id;
	string pickup, dropoff;
    Person(int _id, string PU, string DO) : id(_id), pickup(PU), dropoff(DO), active(false), present(false) {}

    virtual void showDetails() const {
        cout << "ID: " << id << "\nPickup: " << pickup << "\nDropoff: " << dropoff;
        cout << "\nStatus: " << (active ? "Active" : "Inactive") << "\nAttendance: " << (present ? "Present" : "Absent") << endl;
    }

    virtual void payFees() = 0; 
    
    void tapCard(){
        if (active){
            present = true;
            cout << "Attendance marked for ID: " << id << ".\n";
        } else{
            cout << "Payment required! Cannot mark attendance.\n";
        }
    }

    bool operator==(const Person& other) const {
        return id == other.id;
    }
};

class Student : public Person {
public:
    Student(int _id, string PU, string DO) : Person(_id, PU, DO) {}

    void payFees() override {
        if (!active) {
            active = true;
            cout << "Student " << id << " has paid semester fees.\n";
        } else {
            cout << "Fees already paid for Student " << id << ".\n";
        }
    }

    void showDetails() const override {
        cout << "[Student] ";
        Person::showDetails();
    }
};

class Teacher : public Person {
public:
    Teacher(int _id, string PU, string DO) : Person(_id, PU, DO) {}

    void payFees() override {
        if (!active) {
            active = true;
            cout << "Teacher " << id << " has paid monthly transport fees.\n";
        } else {
            cout << "Fees already paid for Teacher " << id << ".\n";
        }
    }

    void showDetails() const override {
        cout << "[Teacher] ";
        Person::showDetails();
    }
};

class StaffMember : public Person {
public:
    StaffMember(int _id, string PU, string DO) : Person(_id, PU, DO) {}

    void payFees() override {
        if (!active) {
            active = true;
            cout << "Staff Member " << id << " has paid monthly transport fees.\n";
        } else {
            cout << "Fees already paid for Staff Member " << id << ".\n";
        }
    }

    void showDetails() const override {
        cout << "[Staff] ";
        Person::showDetails();
    }
};

class Transport {
private:
    int busNo;
    string* stops;
    int totalStops;
    Person** passengers;
    int capacity, passengerCount = 0;

public:
    Transport(int no, string* stopList, int totalStops, int cap) : busNo(no), totalStops(totalStops), capacity(cap) {
        stops = new string[totalStops];
        for (int i = 0; i < totalStops; i++) {
            stops[i] = stopList[i];
        }

        passengers = new Person*[capacity];
        for (int i = 0; i < capacity; i++) {
            passengers[i] = nullptr;
        }
    }

    void registerPerson(Person* p) {
        if (passengerCount < capacity) {
            for (int i = 0; i < totalStops; i++) {
                if (p->pickup == stops[i]) {
                    passengers[passengerCount] = p;
                    passengerCount++;
                    cout << "Person ID " << p->id << " registered for bus " << busNo << ".\n";
                    return;
                }
            }
            cout << "Error: Pickup location does not match bus stops.\n";
        } else {
            cout << "Error: Bus " << busNo << " is full.\n";
        }
    }

    void showTransportDetails() const {
        cout << "\nBus Number: " << busNo << "\nStops: ";
        for (int i = 0; i < totalStops; i++) {
            cout << stops[i] << (i == totalStops - 1 ? "" : ", ");
        }
        cout << "\nCapacity: " << capacity << "\nRegistered Passengers: " << passengerCount << endl;

        for (int i = 0; i < passengerCount; i++) {
            if (passengers[i] != nullptr) {
                passengers[i]->showDetails();
                cout << "-----------------\n";
            }
        }
    }

    bool operator==(const Transport& other) const {
        if (totalStops != other.totalStops) return false;
        for (int i = 0; i < totalStops; i++) {
            if (stops[i] != other.stops[i]) return false;
        }
        return true;
    }

    ~Transport() {
        delete[] stops;
        delete[] passengers;
    }
};

int main() {
    cout << "A2 - Q1 - 24K-0880 - Muhammad Umer Karim" << endl;

    string stopsList[] = {"Stop A", "Stop B", "Stop C", "Stop D"};
    Transport bus1(101, stopsList, 4, 5);

    Student s1(1, "Stop A", "Stop C");
    Student s2(2, "Stop B", "Stop D");
    Teacher t1(3, "Stop A", "Stop B");
    StaffMember sm1(4, "Stop C", "Stop D");

    bus1.registerPerson(&s1);
    bus1.registerPerson(&s2);
    bus1.registerPerson(&t1);
    bus1.registerPerson(&sm1);

    s1.payFees();
    s2.payFees();
    t1.payFees();
    sm1.payFees();

    s1.tapCard();
    t1.tapCard();

    bus1.showTransportDetails();

    Transport bus2(102, stopsList, 4, 5);
    if (bus1 == bus2) {
        cout << "Both buses have the same route.\n";
    } else {
        cout << "Buses have different routes.\n";
    }

    return 0;
}

