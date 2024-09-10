#include<stdio.h>

int main(){
	float amount;
	float discount_p, discount;
	float remaining;
	
	printf("Enter your amount : ");
	scanf("%f", &amount);
	
	
	if(amount < 500){
		printf("Not eligible");
	}
	else if(amount < 2000){
		printf("5%% discount");
		discount_p = 5;
	}
	else if(amount < 4000){
		printf("10%% discount");
		discount_p = 10;
	}
	else if(amount < 6000){
		printf("10%% discount");
		discount_p = 20;
	}
	else{
		printf("35%% discount");
		discount_p = 35;
	}
	
	discount = (discount_p/100) * amount;
	printf("\n Discounted amount %.2f", discount);
	
	remaining = amount - discount;
	printf("\n Total remaining %f.2", remaining);
}