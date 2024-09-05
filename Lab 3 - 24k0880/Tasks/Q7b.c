#include<stdio.h>

int main(){
	float temp, convertedTemp;
	
	printf("Enter temperature in Celsius : ");
	scanf("%f", &temp);
	
	convertedTemp = (9 * (temp) /5) + 32;
	
	printf("Temperature in Fahrenhiet is %f", convertedTemp);
}