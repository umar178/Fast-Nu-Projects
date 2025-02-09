#include<iostream>

using namespace std;

class car{
	private:
		int carnum;
		char carmodel[10];
		
	public:
		void getdata();
		void showdata();	
};

void car::getdata(){
	cout<<"Enter car number: ";
	cin>>carnum;
	cout<<"Enter car Model: ";
	cin>>carmodel;
}

void car::showdata(){
	cout<<"Car number: "<< carnum << endl;
	cout<<"Car Model: " << carmodel;
}

main(){
	car a;
	
	a.getdata();
	a.showdata();
}
