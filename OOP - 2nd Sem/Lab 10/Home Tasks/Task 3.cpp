#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream write("signup.txt",ios::app);
	if(!write){
		cout<<"Error! No file Available"<<endl;
		return 1;
	}
	else{
		string name,email;
		cout<<"Enter Name and Email respectively to signup:"<<endl;
		getline(cin,name);
		getline(cin,email);
		write<<"Name: "<<name<<", Email: "<<email<<"\n";
	}
}
