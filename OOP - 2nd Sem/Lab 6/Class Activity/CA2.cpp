#include <iostream>
using namespace std;

class base {
public:
    int i, b;

    base(int i, int b) {
        this->i = i;
        this->b = b;
    }
};

class derived1 : public base {
public:
    int j, c;

    derived1(int i, int b, int j, int c) : base(i, b) {
        this->j = j;
        this->c = c;
    }

    void showData1() {
        cout << "i = " << i << endl << "b = " << b << endl;
    }
};

class derived2 : public derived1 {
public:
    derived2(int i, int b, int j, int c) : derived1(i, b, j, c) {}

    void showData2() {
        cout << "j = " << j << endl << "c = " << c << endl;
    }
};

int main(){
	derived2 d2(4,5,4,6);
	d2.showData1();
	d2.showData2();
}
