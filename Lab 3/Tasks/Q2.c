#include<stdio.h>

int main(){
	int a, b, temp;
	
	printf("Enter value of a:");
	scanf("%d", &a);
	printf("Enter value of b:");
	scanf("%d", &b);
	
	printf("Swapping values of a & b. \n");
	
	temp = a;
	a = b;
	b = temp;
	
	printf("Swapped value of a now is %d\n", a);
	printf("Swapped value of b now is %d", b);
}