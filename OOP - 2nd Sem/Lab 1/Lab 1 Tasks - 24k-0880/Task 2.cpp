#include<iostream>
using namespace std;

main(){
	int arr[5] = {1,2,3,4,5};
	
	for(int i = 0; i < 3; i++){
		int temp = arr[i];
		arr[i] = arr[5 - i - 1];
		arr[5 - i - 1] = temp;
	}
	
	for(int i = 0; i < 5; i++){
		cout<<arr[i] << " ";
	}
}
