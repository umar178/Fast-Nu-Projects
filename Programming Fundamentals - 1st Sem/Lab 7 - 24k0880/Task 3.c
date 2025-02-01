#include<stdio.h>

int main(){
	int n;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	int arr[n];
	
	for(int i = 0; i < n; i++){
		printf("enter input number %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	
	printf("Array in reverse order is: ");
	
	for(int i = n - 1; i >= 0; i--){
		printf("%d ", arr[i]);
	}
}