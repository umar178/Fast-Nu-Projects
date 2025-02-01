#include<stdio.h>

int main(){
	int arr[] = {25, 30, -2, 35, 42, 28, 10};
	float avg, sum;
	
	for(int i = 0; i < 7; i++){
		if(arr[i] < 0){
			printf("day %d had extreme cold \n", i + 1);
		}
		if(arr[i]>40){
			printf("day %d had extreme heat \n", i + 1);
		}
		
		sum += arr[i];
	}
	
	avg = sum / 7;
	printf("average temp is %d", avg);
}