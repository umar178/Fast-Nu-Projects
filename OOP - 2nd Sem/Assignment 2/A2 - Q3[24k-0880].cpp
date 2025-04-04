#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Vehicle {
protected:
    string vehicleID;
    float speed;
    float capacity;
    float energyEfficiency;
    static int totalDeliveries;

public:
    Vehicle(string id, float s, float c, float ee) 
        : vehicleID(id), speed(s), capacity(c), energyEfficiency(ee) {
        totalDeliveries++;
    }

    virtual void calculateRoute() const = 0;
    
    float calculateDeliveryTime(float distance) const {
        return distance / speed;
    }

    static int getTotalDeliveries() {
        return totalDeliveries;
    }

    virtual void move() const = 0;

    bool operator==(const Vehicle& other) const {
        return (this->speed == other.speed && this->capacity == other.capacity && this->energyEfficiency == other.energyEfficiency);
    }

    virtual ~Vehicle() {}
};

int Vehicle::totalDeliveries = 0;

class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip(string id, float s, float c, float ee) 
        : Vehicle(id, s, c, ee) {}

    void calculateRoute() const override {
        cout << "Time-Ship is verifying historical accuracy before proceeding...\n";
    }

    void move() const override {
        cout << "RamzanTimeShip moves through time to ensure historical accuracy.\n";
    }

    void command(const string& cmd, int urgencyLevel = 0) {
        if (cmd == "Deliver" && urgencyLevel == 1) {
            cout << "Time-Ship treats urgent deliveries as historically sensitive.\n";
        }
        else {
            cout << "Time-Ship delivers on time with historical precision.\n";
        }
    }
};

class RamzanDrone : public Vehicle {
public:
    RamzanDrone(string id, float s, float c, float ee) 
        : Vehicle(id, s, c, ee) {}

    void calculateRoute() const override {
        cout << "RamzanDrone calculates an aerial route for high-speed delivery.\n";
    }

    void move() const override {
        cout << "RamzanDrone flies through the sky to deliver quickly.\n";
    }

    void command(const string& cmd, int urgencyLevel = 0) {
        if (cmd == "Deliver" && urgencyLevel == 1) {
            cout << "RamzanDrone activates high-speed mode for urgent delivery.\n";
        }
        else {
            cout << "RamzanDrone delivers efficiently with low energy consumption.\n";
        }
    }
};

class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod(string id, float s, float c, float ee) 
        : Vehicle(id, s, c, ee) {}

    void calculateRoute() const override {
        cout << "RamzanHyperPod navigates through underground tunnels for efficient bulk delivery.\n";
    }

    void move() const override {
        cout << "RamzanHyperPod travels through high-speed underground networks.\n";
    }

    void command(const string& cmd, int urgencyLevel = 0) {
        if (cmd == "Deliver" && urgencyLevel == 1) {
            cout << "RamzanHyperPod accelerates through the underground tunnels.\n";
        }
        else {
            cout << "RamzanHyperPod delivers large quantities efficiently.\n";
        }
    }
};

class ConflictResolution {
public:
    static void resolveConflict(const Vehicle& v1, const Vehicle& v2) {
        if (v1 == v2) {
            cout << "The vehicles are equally efficient.\n";
        } else {
            if (v1.getTotalDeliveries() > v2.getTotalDeliveries()) {
                cout << "Vehicle 1 has a better delivery track record.\n";
            } else {
                cout << "Vehicle 2 has a better delivery track record.\n";
            }
        }
    }
};

int main() {
	cout << "A2 - Q3 - 24K-0880 - Muhammad Umer Karim" << endl;
    cout << "AI-driven RamzanBox Delivery System - 2030" << endl;

    RamzanTimeShip timeShip("TimeShip001", 100, 2000, 15);
    RamzanDrone drone("Drone001", 250, 50, 30);
    RamzanHyperPod hyperPod("HyperPod001", 500, 5000, 10);

    timeShip.command("Deliver", 1);
    drone.command("Deliver", 0);
    hyperPod.command("Deliver", 1);

    ConflictResolution::resolveConflict(timeShip, drone);
    ConflictResolution::resolveConflict(drone, hyperPod);

    timeShip.move();
    drone.move();
    hyperPod.move();

    return 0;
}

