#include<iostream>
#include<string>

using namespace std;

class car{
	private:
		int year;
		string model;
		string brand;
		
	public:	
		car(string model, int year, string brand){
			this->model = model;
			this->year = year;
			this->brand = brand;
		}
		
		
		void display(){
			cout<<"Model: " << model << endl;
			cout<<"Year: " << year << endl;
			cout<<"Brand: " << brand;
		}
};

main(){
	car a("BRV", 2019, "Honda");
	
	a.display();
}
