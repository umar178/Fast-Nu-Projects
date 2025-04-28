#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream write("greeting.txt");
	string name,message;
	
	if(!write){
		cout<<"Error! No file";
		return 0;
	}
	cout<<"Enter your name: ";
	getline(cin,name);
	
	cout<<"Enter message: ";
	getline(cin,message);
	
	write<<"Dear "<<name<<"\n"<<message<<"\nBest Regards!";
	write.close();
}
