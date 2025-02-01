#include<stdio.h>

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int num;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	for(int i = 0; i <= 9; i++){
		if(arr[i] == num){
			printf("The number is present");
			return 0;
		}
	}
	
	printf("Number not found");
}