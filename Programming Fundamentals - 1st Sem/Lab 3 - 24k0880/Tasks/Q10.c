#include<stdio.h>

int main(){
	float height, weight, BMI;
	
	printf("Enter height in meters : ");
	scanf("%f", &height);
	
	printf("Enter weight in kg : ");
	scanf("%f", &weight);
	
	BMI = weight/height;
	
	printf("Body mass index is %f", BMI);
}
