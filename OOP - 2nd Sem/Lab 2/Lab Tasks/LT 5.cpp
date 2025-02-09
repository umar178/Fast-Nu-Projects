#include<iostream>
#include<string>

using namespace std;

class car{
	private:
		int year;
		string model;
		string color;
		
	public:	
		car(string model, int year, string color){
			this->model = model;
			this->year = year;
			this->color = color;
		}
		
		
		void display(){
			cout<<"Model: " << model << endl;
			cout<<"Year: " << year << endl;
			cout<<"color: " << color;
		}
};

main(){
	car a("Honda", 2019, "Grey");
	
	a.display();
}
