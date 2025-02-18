#include <iostream>
#include <string>
using namespace std;

class Warehouse {
private:
    string location;
    int stockCapacity;

public:
    Warehouse(string l, int s) : location(l), stockCapacity(s) {}

    void display() const {
        cout << "Warehouse at " << location << " | Capacity: " << stockCapacity << " units" << endl;
    }
};

class DeliveryService {
private:
    string serviceID;
    Warehouse* startingPoint;
    Warehouse* currentDestination;

public:
    DeliveryService(string id, Warehouse* start, Warehouse* dest) : serviceID(id), startingPoint(start), currentDestination(dest) {}

    void updateDestination(Warehouse* newDest) {
        currentDestination = newDest;
    }

    void displayStatus() const {
        cout << "Delivery Service: " << serviceID << endl;
        startingPoint->display();
        cout << "Current Destination: ";
        currentDestination->display();
    }
};

int main() {
    Warehouse w1("New York", 1000);
    Warehouse w2("Los Angeles", 1500);
    Warehouse w3("Chicago", 1200);

    DeliveryService ds("DS-001", &w1, &w2);
    ds.displayStatus();

    ds.updateDestination(&w3);
    cout << "After updating the destination:" << endl;
    ds.displayStatus();

    return 0;
}
