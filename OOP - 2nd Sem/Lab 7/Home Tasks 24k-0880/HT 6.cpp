#include<iostream>
using namespace std;
class SmartDevice{
	public:
		virtual void performAction(){
			cout<<"Each appliances has its own function"<<endl;
		}
};

class SmartLight:public SmartDevice{
	public:
		void performAction()override{
			cout<<"Smart Light: Turning on the lights."<<endl;
		}
};

class SmartThermostat:public SmartDevice{
	public:
		void performAction()override{
			cout<<"Smart Thermostat: Setting temperature to 22?C."<<endl;
		}
};

int main(){
	SmartDevice *d1;
	SmartDevice *d2;
	SmartLight l1;
	SmartThermostat t1;
	d1=&l1;
	d2=&t1;
	d1->performAction();
	d2->performAction();
}
