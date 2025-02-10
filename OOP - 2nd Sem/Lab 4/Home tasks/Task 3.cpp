#include <iostream>
using namespace std;

class Temperature {
    double celsius;
public:
    Temperature(double c = 25.0) : celsius(c) {
        cout << " Temperature object created with " << celsius << "°C" << endl;
    }
    ~Temperature() { 
		cout << " Temperature object deleted" << endl; 
	}
    double toFahrenheit() { return (celsius * 9 / 5) + 32; }
    double toKelvin() { return celsius + 273.15; }
    void displayTemperature() {
        cout << " Celsius: " << celsius << "C | Fahrenheit: " << toFahrenheit() << "F | Kelvin: " << toKelvin() << "K" << endl;
    }
};

int main() {
	double t;
	cin>>t;
    Temperature temp(t);
    temp.displayTemperature();
}
