#include <iostream>
using namespace std;

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        return b != 0 ? a / b : 0;
    }
};

int main() {
    Calculator calc;
    double num1, num2;
    char operation;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Add: " << calc.add(num1, num2) << endl;
  	cout << "Sub: " << calc.subtract(num1, num2) << endl;
    cout << "Multiply: " << calc.multiply(num1, num2) << endl;
    
    if (num2 != 0)
        cout << "Divide: " << calc.divide(num1, num2) << endl;
    else
        cout << "Cannot divide by zero" << endl;

    return 0;
}


