#include<iostream>
using namespace std;

template <typename T>
void swapValues(T *a,T *b){
	cout<<"Before swap: a="<<*a<<",b="<<*b<<endl;
	T temp;
	temp=*a;
	*a=*b;
	*b=temp;
	cout<<"After swap: a="<<*a<<",b="<<*b<<endl;
}

int main(){
	int a=5,b=10;
	swapValues(&a,&b);
	
	float x=3.5,y=7.8;
	swapValues(&x,&y);
	
	char ch1='A',ch2='Z';
	swapValues(&ch1,&ch2);
	
}
