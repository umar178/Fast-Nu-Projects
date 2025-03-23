#include <iostream>
using namespace std;

class Transport {
protected:
    string vehicleType;
    int capacity;

public:
    Transport(string v, int c) : vehicleType(v), capacity(c) {}
};

class RoadTransport : virtual public Transport {
protected:
    string roadType;

public:
    RoadTransport(string v, int c, string r) : Transport(v, c), roadType(r) {}
};

class AirTransport : virtual public Transport {
protected:
    int maxAltitude;

public:
    AirTransport(string v, int c, int a) : Transport(v, c), maxAltitude(a) {}
};

class HybridVehicle : public RoadTransport, public AirTransport {
private:
    double fuelEfficiency;

public:
    HybridVehicle(string v, int c, string r, int a, double f)
        : Transport(v, c), RoadTransport(v, c, r), AirTransport(v, c, a), fuelEfficiency(f) {}

    void displayDetails() const {
        cout << "=== Hybrid Vehicle Details ===\n";
        cout << "Vehicle Type: " << vehicleType << "\nMax Capacity: " << capacity << " passengers";
        cout << "\nRoad Type: " << roadType << "\nMax Altitude: " << maxAltitude << " feet";
        cout << "\nFuel Efficiency: " << fuelEfficiency << " km/l\n";
    }
};

int main() {
    HybridVehicle hv("Hybrid", 5, "SUV", 10000, 15.5);
    hv.displayDetails();
    return 0;
}

