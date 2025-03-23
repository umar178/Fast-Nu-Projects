#include<stdio.h>
using namespace std;

class A{
	int A_num;
	public:
		A(int num){
			A_num = num;
		}
};

class B: public A{
	int B_num;
	public:
		B(int num, int num2) : A(num){
			B_num = num2;
		}
};

class C: public B{
	int C_num;
	public:
		C(int num1, int num2, int num3) : B(num1, num2){
			C_num = num3;
		}
};

int main(){
	
}
