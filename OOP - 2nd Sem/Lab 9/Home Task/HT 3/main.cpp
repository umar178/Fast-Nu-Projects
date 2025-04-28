#include <iostream>
#include "Calculator.h"

int main() {
    double x = 10.5, y = 5.2;
    
    std::cout << "Addition: " << Calculator::add(x, y) << std::endl;
    std::cout << "Subtraction: " << Calculator::subtract(x, y) << std::endl;
    std::cout << "Multiplication: " << Calculator::multiply(x, y) << std::endl;
    std::cout << "Division: " << Calculator::divide(x, y) << std::endl;
    
    return 0;
}
