#include<stdio.h>

int main(){
	float km, miles;
	
	printf("Enter kilometers : ");
	scanf("%f", &km);
	
	miles = km * 1.609344;
	
	printf("kilometer to miles is %f", miles);
}