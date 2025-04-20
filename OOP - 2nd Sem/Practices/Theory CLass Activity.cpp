#include<iostream>
using namespace std;

class payment{
	public:
		virtual void pay() = 0;
};

class sadapay: public payment{
	public:
		void pay(){
			cout<<"Sadapay\n";
		}
};

class Paypak: public payment{
	public:
		void pay(){
			cout<<"PayPak\n";
		}
};

class Payoneer: public payment{
	public:
		void pay(){
			cout<<"Payoneer\n";
		}
};

main(){
  sadapay *s = new sadapay;
  s->pay();
  Paypak *p = new Paypak;
  p->pay();
  Payoneer *p1 = new Payoneer;
  p1->pay();
}
