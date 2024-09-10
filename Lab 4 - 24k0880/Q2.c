#include<stdio.h>

int main(){
	char op;
	int n1, n2;
	
	printf("Enter Operation (+, -, *, /) : ");
	scanf("%c", &op);
	
	printf("Enter number 1: ");
	scanf("%d", &n1);
	
	printf("Enter number 2: ");
	scanf("%d", &n2);
	
	
	
	switch(op){
		
		case '+':
			printf("Sum = %d", n1 + n2);
			break;
			
		case '-':
			printf("Difference = %d", n1 - n2);
			break;
			
		case '*':
			printf("Product = %d", n1 * n2);
			break;
			
		case '/':
			printf("Division = %d", n1 / n2);
			break;	
			
		default:
			printf("Enter a valid operation");
			break;
	}
}