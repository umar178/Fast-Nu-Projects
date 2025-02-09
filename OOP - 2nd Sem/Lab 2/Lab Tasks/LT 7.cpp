#include<iostream>
#include<string>

using namespace std;

class shape{
	private:
		string name;
		int length;
		int hieght;
		
	public:	
		shape(int l, int h, string name){
			this->name = name;
			length = l;
			hieght = h;
		}
		
		
		void display(){
			cout<<"Name: " << name << endl;
			cout<<"Length: " << length << endl;
			cout<<"Hieght: " << hieght;
		}
		
		void area(){
			cout <<"\nArea: "<< length*hieght;
		}
};

main(){
	shape a(5, 7, "Rectangle");
	
	a.display();
	a.area();
}
