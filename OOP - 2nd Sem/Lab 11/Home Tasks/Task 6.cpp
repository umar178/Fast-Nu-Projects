#include<iostream>
using namespace std;

class HealthCare{
	int age;
	double salary;
	float height;
	public:
		void validataAge(){
			cout<<"Enter age: ";
			cin>>age;
			if(!(age>0 && age<120)){
				throw "InvalidAgeException";
			}
		}
		
		void validateSalary(){
			cout<<"Enter salary: ";
			cin>>salary;
			if(!(salary>0)){
				throw "InvalidSalaryException";
			}
		}
		
		void validateHeight(){
			cout<<"Enter height: ";
			cin>>height;
			if(!(height>0)){
				throw "InvalidHeightException";
			}
		}
};

int main(){
	HealthCare c1;
	try{
		c1.validataAge();
	}
	catch(const char *c){
		cout<<c<<" caught: Age must be between 1 and 119"<<endl;
	}
	
	try{
		c1.validateSalary();
	}
	catch(const char *c){
		cout<<c<<" caught: Salary must be positive"<<endl;
	}
	
	try{
		c1.validateHeight();
	}
	catch(const char *c){
		cout<<c<<" caught: Height must be positive"<<endl;
	}
	
}
