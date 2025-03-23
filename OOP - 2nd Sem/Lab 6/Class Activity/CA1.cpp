#include <iostream>
using namespace std;

class base {
   public:
     int i, b;

     base(int i, int b) {
      this->i=1;
      this->b=b;
}
};

class derived : public base {
  public:
  	  derived(int x,int y): base(x,y){}
  	  
      void showData() { cout << "i="<<i<< endl << "b=" << b; }
};
int main() {
    derived d1(4, 5);
    d1.showData();
}
