#include<stdio.h>

int main(){
	int arr[] = {4,1,6,8,10,21,8,9,2,6};
	int min = 32000, max = 0;
	
	for(int i = 0; i < 10; i++){
		min = (min > arr[i])? arr[i]: min;
		max = (max < arr[i])? arr[i]: max;
	}
	printf("max number is %d \n", max);
	printf("min number is %d \n", min);
	
}