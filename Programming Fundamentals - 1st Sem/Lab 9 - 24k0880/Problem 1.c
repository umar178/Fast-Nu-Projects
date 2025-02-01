#include<stdio.h>

int product(int a, int b){
	return a * b;
}

main(){
	int a, b;
	
	printf("enter number 1: ");
	scanf("%d", &a);
	printf("enter number 2: ");
	scanf("%d", &b);
	
	printf("product = %d", product(a, b));
}