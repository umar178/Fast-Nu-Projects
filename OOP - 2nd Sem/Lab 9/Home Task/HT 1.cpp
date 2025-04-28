#include <iostream>
using namespace std;

class Car {
private:
    bool engineOn;
    double fuelLevel;
    double speed;

public:
    Car() : engineOn(false), fuelLevel(0.0), speed(0.0) {}

    void startEngine() {
        if (fuelLevel > 0) {
            engineOn = true;
            cout << "Engine started." << endl;
        } else {
            cout << "Cannot start engine - no fuel!" << endl;
        }
    }

    void stopEngine() {
        engineOn = false;
        speed = 0.0;
        cout << "Engine stopped." << endl;
    }

    void refuel(double amount) {
        fuelLevel += amount;
        cout << "Refueled. Current fuel level: " << fuelLevel << " liters." << endl;
    }

    void setSpeed(double newSpeed) {
        if (engineOn) {
            speed = newSpeed;
            cout << "Speed set to " << speed << " km/h." << endl;
        } else {
            cout << "Cannot set speed - engine is off!" << endl;
        }
    }

    double getSpeed() const {
        return speed;
    }
};

int main() {
    Car myCar;
    myCar.refuel(20.0);
    myCar.startEngine();
    myCar.setSpeed(60.5);
    cout << "Current speed: " << myCar.getSpeed() << " km/h" << endl;
    myCar.stopEngine();
    return 0;
}
