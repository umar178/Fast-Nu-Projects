#include <iostream>
using namespace std;

class Rectangle {
private:
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}
    friend float calculateArea(const Rectangle& r);
};

float calculateArea(const Rectangle& r) {
    return r.length * r.width;
}

int main() {
    Rectangle r1(5.5, 3.2);
    cout << "Area of Rectangle: " << calculateArea(r1) << endl;
    return 0;
}

