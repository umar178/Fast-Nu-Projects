#include <iostream>
#include <string>
using namespace std;

class SmartEnergyDevice {
    string deviceName, deviceType;
    double powerRating, hoursUsed;
public:
    SmartEnergyDevice(string name = "Smart AC", string type = "Air Conditioner", double power = 1500.0) : deviceName(name), deviceType(type), powerRating(power), hoursUsed(0) {
        cout << deviceName << " (" << deviceType << ") is now active!" << endl;
    }
    
    ~SmartEnergyDevice() { 
		cout << deviceName << " (" << deviceType << ") is removed from tracking." << endl; 
	}
	
    void useDevice(double hours) { hoursUsed += hours; }
    double calculateEnergyConsumption() { return (powerRating * hoursUsed) / 1000; }
    
    void displayEnergyUsage() {
        cout << "Device: " << deviceName << " | Type: " << deviceType << " | Power: " << powerRating << "W | Hours Used: " << hoursUsed << " | Energy Consumed: " << calculateEnergyConsumption() << " kWh" << endl;
    }
};

int main() {
    SmartEnergyDevice heater("Smart Heater", "Heater", 2000);
    SmartEnergyDevice ac("Smart AC", "Air Conditioner", 1500);
    heater.useDevice(5);
    ac.useDevice(8);
    heater.displayEnergyUsage();
    ac.displayEnergyUsage();
}
