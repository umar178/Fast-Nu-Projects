#include<iostream>
using namespace std;
class Complex{
	int real;
	int imaginary;
	public:
		Complex(int real,int imaginary):real(real),imaginary(imaginary){}
		void display(){
			cout<<" "<<real<<" + "<<imaginary<<"i"<<endl;
		}
		Complex operator+(const Complex &obj){
			return Complex(real+obj.real,imaginary+obj.imaginary);
		}
		Complex operator*(const Complex &obj){
			return Complex(real*obj.real,imaginary*obj.imaginary);
		}
};

int main(){
	Complex c1(4,5);
	Complex c2(9,-10);
	Complex c3=c1+c2;
	cout<<"Sum:";
	c3.display();
	Complex c4=c1*c2;
	cout<<"Product:";
	c4.display();
}

