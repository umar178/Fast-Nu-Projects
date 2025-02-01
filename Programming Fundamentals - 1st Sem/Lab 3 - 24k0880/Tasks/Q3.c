#include<stdio.h>

int main(){
	float salary, taxRate;
	float totalTax, remaining;
	
	printf("Enter your salary: ");
	scanf("%f", &salary);
	printf("Enter tax rate in percentage: ");
	scanf("%f", &taxRate);
	
	printf("Calculating..........\n");
	
	totalTax = (taxRate/100) * salary;
	remaining = salary - totalTax;
	
	printf("Payable tax is %f\n", totalTax);
	printf("Remaining salary is %f", remaining);
}