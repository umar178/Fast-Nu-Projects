#include<stdio.h>

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int sum = 0;
	
	for(int i = 0; i <= 9; i++){
		sum += i;
	}
	
	printf("Sum is %d", sum);
}