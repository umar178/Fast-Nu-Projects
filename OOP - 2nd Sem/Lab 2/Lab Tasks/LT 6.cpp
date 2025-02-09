#include<iostream>
#include<string>

using namespace std;

double area(int h, int l){
	return l*h;
}

int main(){
	double length, hieght;
	
	cout<< "Enter Length: ";
	cin>> length;
	cout<<"Enter Hieght: ";
	cin>>hieght;
	
	cout<<"Area: "<<area(length, hieght);
}
