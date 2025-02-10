#include <iostream>
#include <string>
using namespace std;

class Car {
    string carName;
    double fuelCapacity, fuelConsumptionRate, distanceDriven;
public:
    Car(string name = "Suzuki WagonR", double capacity = 35.0, double rate = 5.0) : carName(name), fuelCapacity(capacity), fuelConsumptionRate(rate), distanceDriven(0) {
        cout << "Car " << carName << " is ready to drive!" << endl;
    }
    
    ~Car() { 
		cout << "Car " << carName << " is removed from tracking." << endl; 
	}
	
    void drive(double distance) {
        fuelCapacity -= (distance / 100) * fuelConsumptionRate;
        distanceDriven += distance;
        cout << "Drove " << distance << " km. Remaining fuel: " << fuelCapacity << " liters" << endl;
    }
    
    void refuel(double liters) {
        fuelCapacity += liters;
        cout << "Refueled " << liters << " liters. Current fuel level: " << fuelCapacity << " liters" << endl;
    }
    
    void displayCarStatus() {
        cout << "Car: " << carName << " | Distance Driven: " << distanceDriven << " km | Fuel Remaining: " << fuelCapacity << " liters" << endl;
    }
};

int main() {
    Car car;
    car.drive(200);
    car.refuel(10);
    car.displayCarStatus();
}
