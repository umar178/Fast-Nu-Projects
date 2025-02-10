#include <iostream>
using namespace std;

class DigitalClock {
private:
    int hours;
    int minutes;

public:
    DigitalClock(int h = 7, int m = 30) : hours(h), minutes(m) {
        cout << "Digital Clock Initialized: " << hours << ":" << minutes << endl;
    }

    ~DigitalClock() {
        cout << "Digital Clock Destroyed!" << endl;
    }

    void displayTime() {
        cout << "Current Time: " << hours << ":" << minutes << endl;
    }
};

int main() {
    DigitalClock clock(7, 30);
    clock.displayTime();
    return 0;
}
