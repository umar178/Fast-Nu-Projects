#include<iostream>
#include<limits>
#include<cmath>
using namespace std;

void greet(){
	cout<<"Hello World";
}

void print(int num){
	cout << num << endl;
}

int sum(int x, int y){
	return x+y;
}

void arrays(){
	int item[5], sum, counter;
	
	cout<< "Enter 5 numbers: " << endl;
	
	for(int i = 0; i<5; i++){
		cin >> item[i];
	}
	
	cout << "Numbers are:"<< endl;
	
	for(int i = 0; i<5; i++){
		cout << item[i] << endl;
	}
	
}

void arraysum(){
	int item[2][2], sum, counter;
	
	cout<< "Enter 4 numbers: " << endl;
	
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			cin >> item[i][j];
		}
	}
	
	
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			sum += item[i][j];
		}
	}
	
	cout << "sum is: " << sum << endl;
}

main(){
	int num;
	double x = 26.0, sqt;
	
	arraysum();
	
	sqt = sqrt(x);
	cout<<"square root of " << x << " is: "<< sqt << endl;
	
	cout<< "Enter a number: ";
	cin>> num;
	cout<< "Number is: " << num << endl;
	
	cout<<"Size of integer: " << sizeof(int) << endl;
	
	cout<<"Int Min: " << std::numeric_limits<int>::min() << endl;
	cout<<"Int Max: " << std::numeric_limits<int>::max();
	
	return 0;
}



