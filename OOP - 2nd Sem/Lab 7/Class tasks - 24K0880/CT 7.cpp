#include <iostream>
using namespace std;
class Shape {
public:
    void draw() {
        cout << "Drawing Shape" << endl;
    }
};
class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};
int main() {
    Shape* s = new Circle;
    s->draw();
    delete s;
    return 0;
}

