#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Vehicle {
protected:
    string vehicleID;
    double maxSpeed;
    double capacity;
    double energyEfficiency;
    static int activeDeliveries;

public:
    Vehicle(string id, double speed, double cap, double efficiency) 
        : vehicleID(id), maxSpeed(speed), capacity(cap), energyEfficiency(efficiency) {
        activeDeliveries++;
    }

    virtual ~Vehicle() {
        activeDeliveries--;
    }

    virtual string calculateRoute(string destination) {
        return "Standard route to " + destination;
    }

    virtual double estimateDeliveryTime(string destination, double distance) {
        return distance / maxSpeed;
    }

    virtual void command(string cmd) {
        cout << "[" << vehicleID << "] Command received: " << cmd << endl;
    }

    virtual void command(string cmd, string packageID) {
        cout << "[" << vehicleID << "] Command received: " << cmd 
             << " | Package: " << packageID << endl;
    }

    virtual void command(string cmd, string packageID, string urgencyLevel) {
        cout << "[" << vehicleID << "] Command received: " << cmd 
             << " | Package: " << packageID << " | Urgency: " << urgencyLevel << endl;
    }

    static int getActiveDeliveries() {
        return activeDeliveries;
    }

    string getID() const { return vehicleID; }
    double getSpeed() const { return maxSpeed; }
    double getCapacity() const { return capacity; }
    double getEfficiency() const { return energyEfficiency; }

    friend int compareEfficiency(const Vehicle& v1, const Vehicle& v2);

    bool operator==(const Vehicle& other) const {
        return (maxSpeed == other.maxSpeed) && 
               (capacity == other.capacity) && 
               (energyEfficiency == other.energyEfficiency);
    }
};

int Vehicle::activeDeliveries = 0;

int compareEfficiency(const Vehicle& v1, const Vehicle& v2) {
    double score1 = v1.maxSpeed * 0.4 + v1.capacity * 0.3 + v1.energyEfficiency * 0.3;
    double score2 = v2.maxSpeed * 0.4 + v2.capacity * 0.3 + v2.energyEfficiency * 0.3;
    
    if (score1 > score2) return 1;
    else if (score1 < score2) return -1;
    else return 0;
}

class RamzanDrone : public Vehicle {
private:
    double altitude;
    bool highSpeedMode;

public:
    RamzanDrone(string id, double speed, double cap, double efficiency, double alt)
        : Vehicle(id, speed, cap, efficiency), altitude(alt), highSpeedMode(false) {}

    string calculateRoute(string destination) override {
        return "Aerial route to " + destination + " (Altitude: " + to_string((int)altitude) + "m)";
    }

    double estimateDeliveryTime(string destination, double distance) override {
        if (highSpeedMode) {
            return distance / (maxSpeed * 1.5);
        }
        return distance / maxSpeed;
    }

    void command(string cmd, string packageID, string urgencyLevel) override {
        cout << "[" << vehicleID << "] IFTAR DELIVERY INITIATED | Package: " << packageID << endl;
        if (urgencyLevel == "Iftar") {
            highSpeedMode = true;
            cout << "  HIGH SPEED MODE ACTIVATED (Priority: Iftar Meal)" << endl;
        }
    }

    void activateAntiCollision() {
        cout << "[" << vehicleID << "] Anti-collision system activated" << endl;
    }
};

class RamzanTimeShip : public Vehicle {
private:
    string timePeriod;
    bool historicalValidation;

public:
    RamzanTimeShip(string id, double speed, double cap, double efficiency, string period)
        : Vehicle(id, speed, cap, efficiency), timePeriod(period), historicalValidation(false) {}

    string calculateRoute(string destination) override {
        return "Time route to " + destination + " in " + timePeriod + " era | Validation: " 
               + (historicalValidation ? "CONFIRMED" : "PENDING");
    }

    double estimateDeliveryTime(string destination, double distance) override {
        return historicalValidation ? 0.1 : 5.0;
    }

    void command(string cmd, string packageID, string urgencyLevel) override {
        cout << "[" << vehicleID << "] HISTORICAL DELIVERY | Package: " << packageID << endl;
        if (urgencyLevel == "Sehri") {
            historicalValidation = true;
            cout << "  Historical validation initiated (Priority: Sehri Package)" << endl;
        }
    }

    void validateHistoricalAccuracy() {
        historicalValidation = true;
        cout << "[" << vehicleID << "] History validated for " << timePeriod << " era" << endl;
    }
};

class RamzanHyperPod : public Vehicle {
private:
    string tunnelNetwork;
    bool bulkMode;

public:
    RamzanHyperPod(string id, double speed, double cap, double efficiency, string network)
        : Vehicle(id, speed, cap, efficiency), tunnelNetwork(network), bulkMode(false) {}

    RamzanHyperPod(string id, double speed, double cap, double efficiency)
        : RamzanHyperPod(id, speed, cap, efficiency, "Primary Hyperloop Network") {}

    string calculateRoute(string destination) override {
        return "Underground route to " + destination + " via " + tunnelNetwork 
               + (bulkMode ? " | BULK MODE ACTIVE" : "");
    }

    double estimateDeliveryTime(string destination, double distance) override {
        if (bulkMode) {
            return (distance / maxSpeed) * 1.2;
        }
        return distance / maxSpeed;
    }

    void command(string cmd, string packageID) override {
        cout << "[" << vehicleID << "] BULK DELIVERY INITIATED | Package: " << packageID << endl;
        bulkMode = true;
        cout << "  Bulk transport mode activated" << endl;
    }

    void optimizeTunnelRoute() {
        cout << "[" << vehicleID << "] Optimizing tunnel route in " << tunnelNetwork << endl;
    }
};

void resolveDeliveryConflict(Vehicle* v1, Vehicle* v2, string packageID, string urgency) {
    cout << "\nDELIVERY CONFLICT RESOLUTION" << endl;
    cout << "============================" << endl;
    cout << "Package: " << packageID << " (" << urgency << ")" << endl;
    cout << "Contenders: " << v1->getID() << " vs " << v2->getID() << endl;
    
    int result = compareEfficiency(*v1, *v2);
    
    if (result == 1) {
        cout << "Decision: " << v1->getID() << " selected (more efficient)" << endl;
        v1->command("Deliver", packageID, urgency);
    } 
    else if (result == -1) {
        cout << "Decision: " << v2->getID() << " selected (more efficient)" << endl;
        v2->command("Deliver", packageID, urgency);
    }
    else {
        cout << "Decision: Both vehicles equally efficient" << endl;
        cout << "Defaulting to " << v1->getID() << endl;
        v1->command("Deliver", packageID, urgency);
    }
    cout << "============================\n" << endl;
}

int main() {
	cout << "A2 - Q3 - 24K-0880 - Muhammad Umer Karim" << endl;
    cout << "RAMZAN BOX DELIVERY SYSTEM INITIALIZING...\n" << endl;

    RamzanDrone drone("DRONE-001", 120, 5, 0.9, 150);
    RamzanTimeShip timeship("TIMESHIP-001", 500, 20, 0.7, "21st Century");
    RamzanHyperPod hyperpod("HYPERPOD-001", 300, 100, 0.8);
    
    cout << "\nTESTING VEHICLE COMMANDS:\n" << endl;
    drone.command("Deliver", "IFTAR-MEAL-001", "Iftar");
    timeship.command("Deliver", "SEHRI-PACKAGE-001", "Sehri");
    hyperpod.command("Deliver", "BULK-FOOD-001");
    
    cout << "\nTESTING ROUTE CALCULATIONS:\n" << endl;
    Vehicle* vehicles[3] = {&drone, &timeship, &hyperpod};
    for (int i = 0; i < 3; i++) {
        cout << vehicles[i]->getID() << ": " << vehicles[i]->calculateRoute("Central Mosque") << endl;
    }
    
    cout << "\nTESTING DELIVERY TIME ESTIMATES:\n" << endl;
    for (int i = 0; i < 3; i++) {
        cout << vehicles[i]->getID() << ": " << fixed << setprecision(1) 
             << vehicles[i]->estimateDeliveryTime("Central Mosque", 60) << " hours" << endl;
    }
    
    cout << "\nTESTING CONFLICT RESOLUTION:\n" << endl;
    resolveDeliveryConflict(&drone, &timeship, "SPECIAL-IFTAR-001", "Iftar");
    resolveDeliveryConflict(&timeship, &hyperpod, "HISTORICAL-SEHRI-001", "Sehri");
    
    RamzanDrone drone2("DRONE-002", 120, 5, 0.9, 150);
    if (drone == drone2) {
        cout << "VEHICLE COMPARISON: " << drone.getID() << " and " << drone2.getID() 
             << " have identical specifications" << endl;
    }
    
    cout << "\nSYSTEM STATISTICS:" << endl;
    cout << "Active deliveries: " << Vehicle::getActiveDeliveries() << endl;
    
    cout << "\nRAMZAN BOX DELIVERY SYSTEM SHUTTING DOWN..." << endl;
    return 0;
}
