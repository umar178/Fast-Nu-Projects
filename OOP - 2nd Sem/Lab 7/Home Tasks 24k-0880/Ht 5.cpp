#include<iostream>
using namespace std;
class Payment{
	public:
		virtual void processPayment(){
			cout<<"Process of payment"<<endl;
		}
};

class CreditCard:public Payment{
	public:
		void processPayment()override{
			cout<<"Processing Credit Card Payment..."<<endl;
		}
};

class PayPal:public Payment{
	public:
		void processPayment()override{
			cout<<"Processing PayPal Payment..."<<endl;
		}
};

int main(){
	Payment *p1;
	Payment *p2;
	CreditCard c1;
	PayPal py1;
	p1=&c1;
	p2=&py1;
	p1->processPayment();
	p2->processPayment();
}
