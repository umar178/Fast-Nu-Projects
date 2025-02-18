#include <iostream>
#include <string>
using namespace std;

class Runner {
private:
    string name;
    double speed;
    static const double MAX_SPEED;

public:
    Runner(string n, double s) : name(n), speed(s) {}

    void display() const {
        cout << "Runner: " << name << " | Speed: " << speed << " km/h";
        if (speed > MAX_SPEED) {
            cout << " (Disqualified: Exceeded Speed Limit)";
        }
        cout << endl;
    }

    static void displayMaxSpeed() {
        cout << "Max Speed Limit for Marathon: " << MAX_SPEED << " km/h" << endl;
    }
};

const double Runner::MAX_SPEED = 25.0;

int main() {
    Runner::displayMaxSpeed();

    Runner r1("Usain Bolt", 27.8);
    Runner r2("Eliud Kipchoge", 21.5);
    Runner r3("Mo Farah", 24.0);

    r1.display();
    r2.display();
    r3.display();

    return 0;
}
