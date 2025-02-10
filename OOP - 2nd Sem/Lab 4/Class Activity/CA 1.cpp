#include<iostream>

using namespace std;

class product{
	string name;
	double price;
	
	public:
		product(){
			name = "Unknown";
			price = 0.0;
		}
		
		void addProduct(string name, double price){
			this->name = name;
			this->price = price;
			cout<<"Product " << name << " added at a price of " << price << "$" << endl;
		}
		
		void updatePrice(double price){
			this->price = price;
			cout<<"Price Updated to " << price << "$ for " << name << endl;
		}
		
		void display(){
			cout<< "Product: " << name << endl << "Price: " << price << "$"<< endl;
		}
};

main(){
	product p;
	p.display();
	
	p.addProduct("Apple", 20);
	p.updatePrice(15);
	p.display();
}
