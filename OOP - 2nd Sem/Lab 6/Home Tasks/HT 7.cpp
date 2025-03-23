#include <iostream>
using namespace std;

class Device {
protected:
    string deviceName;
    bool powerStatus;

public:
    Device(string n) : deviceName(n), powerStatus(false) {}

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class SmartLight : virtual public Device {
public:
    SmartLight() : Device("Smart Light") {}

    void turnOn() override {
        powerStatus = true;
        cout << "Smart Light is ON with adjustable brightness.\n";
    }

    void turnOff() override {
        powerStatus = false;
        cout << "Smart Light is now OFF.\n";
    }
};

class SmartFan : virtual public Device {
public:
    SmartFan() : Device("Smart Fan") {}

    void turnOn() override {
        powerStatus = true;
        cout << "Smart Fan is ON at medium speed.\n";
    }

    void turnOff() override {
        powerStatus = false;
        cout << "Smart Fan is now OFF.\n";
    }
};

class SmartRoom : public SmartLight, public SmartFan {
public:
    SmartRoom() : Device("Smart Room") {}

    void activateRoom() {
        SmartLight::turnOn();
        SmartFan::turnOn();
        cout << "Smart Room is now fully activated!\n";
    }

    void deactivateRoom() {
        SmartLight::turnOff();
        SmartFan::turnOff();
    }
};

int main() {
    SmartRoom sr;
    sr.activateRoom();
    sr.deactivateRoom();
    return 0;
}

