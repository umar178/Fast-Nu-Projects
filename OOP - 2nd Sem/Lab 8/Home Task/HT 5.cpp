#include <iostream>
using namespace std;

class HomeAssistant;

class SmartDevice {
private:
    string deviceName;
    float powerUsage;
    bool status;

public:
    SmartDevice(string n, float p) : deviceName(n), powerUsage(p), status(false) {}
    friend class HomeAssistant;
    friend float EnergyMonitor(SmartDevice* devices[], int count);
};

class HomeAssistant {
public:
    void turnOn(SmartDevice& d) { d.status = true; }
    void turnOff(SmartDevice& d) { d.status = false; }
};

float EnergyMonitor(SmartDevice* devices[], int count) {
    float total = 0;
    for (int i = 0; i < count; ++i) {
        if (devices[i]->status) total += devices[i]->powerUsage;
    }
    return total;
}

int main() {
    SmartDevice d1("Light", 10), d2("Fan", 30), d3("AC", 100);
    SmartDevice* devices[] = { &d1, &d2, &d3 };

    HomeAssistant ha;
    ha.turnOn(d1);
    ha.turnOn(d3);

    cout << "Total Energy Consumption: " << EnergyMonitor(devices, 3) << "W" << endl;
    return 0;
}

