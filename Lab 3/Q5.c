#include<stdio.h>

int main(){
	float principle, interestRate, time, Total;
	
	printf("Enter principle value, Between 100 to 1,000,000 : ");
	scanf("%f", &principle);
	
	printf("Enter interest rate, Between 5 to 10 percent : ");
	scanf("%f", &interestRate);
	
	printf("Enter Time period, Between 1 to 10 years : ");
	scanf("%f", &time);
	
	Total = principle * (interestRate/100) * time;
	
	printf("Total interest is %f", Total);
}