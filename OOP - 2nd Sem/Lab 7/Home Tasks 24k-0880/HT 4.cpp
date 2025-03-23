#include<iostream>
using namespace std;
class Animal{
	public:
	virtual void makeSound(){
		cout<<"Each and every Animal makes sound"<<endl;
	}
};

class Dog:public Animal{
	public:
	void makeSound()override{
		cout<<"Dog:Woof!"<<endl;
	}
};

class Cat:public Animal{
	public:
	void makeSound()override{
		cout<<"Cat:Meow!"<<endl;
	}
};

int main(){
	Animal *a1;
	Animal *a2;
	Dog d1;
	a1=&d1;
	Cat c1;
	a2=&c1;
	a1->makeSound();
	a2->makeSound();
}
