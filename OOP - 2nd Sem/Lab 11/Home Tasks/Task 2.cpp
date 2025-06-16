#include<iostream>
using namespace std;
template <typename T>
class Calculator{
	private:
		T numerator;
		T denominator;
	public:
		void Division(){
			cout<<"Enter numerator: ";
			cin>>numerator;
			cout<<"Enter denominator: ";
			cin>>denominator;
			if(denominator==0){
				throw 0;
			}
			cout<<"Result: "<<(numerator/denominator)<<endl;
		}
};

int main(){
	Calculator<int> c1;
	Calculator<int> c2;
	try{
		c2.Division();
	}
	catch(int a){
		cout<<"Error: Division by zero is not allowed!"<<endl;
	}
	
	try{
		c1.Division();
	}
	catch(int a){
		cout<<"Error: Division by zero is not allowed!"<<endl;
	}
	
}
