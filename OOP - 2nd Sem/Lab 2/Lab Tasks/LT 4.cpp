#include<iostream>
#include<string>

using namespace std;

class car{
	private:
		int year;
		string model;
		
	public:	
		car(string n, int m) : model(n), year(m) {}
		
		void display(){
			cout<<"Model: " << model << endl;
			cout<<"Year: " << year;
		}
};

main(){
	car a("Honda", 2019);
	
	a.display();
}
