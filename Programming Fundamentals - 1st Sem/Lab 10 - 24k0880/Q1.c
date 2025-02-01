#include<stdio.h>

void arrprint(int arr[], int size){
	if(size > 0){
		arrprint(arr, size - 1);
		printf("%d\n", arr[size]);
	}
	else{
		printf("%d\n", arr[size]);
	}
}

int main(){
	int arr[] = {2,4,5,1,8,9,0,3};
	
	arrprint(arr, 7);
}