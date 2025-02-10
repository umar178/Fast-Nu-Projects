#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle(int l, int w) : length(l), width(w) {
    cout << "Rectangle object created with length = " << length
    << " and width = " << width << endl;
    }

    int area() {
    return length * width;
    }

    ~Rectangle() {
    cout << "Rectangle object destroyed." << endl;
    }
};

int main() {
    Rectangle rect(5, 10);
    cout << "Area of the rectangle: " << rect.area() << endl;
}
