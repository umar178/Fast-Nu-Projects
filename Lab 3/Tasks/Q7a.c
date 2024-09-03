#include<stdio.h>

int main(){
	float temp, convertedTemp;
	
	printf("Enter temperature in fahrenhiet : ");
	scanf("%f", &temp);
	
	convertedTemp = (temp - 32) * 5/9;
	
	printf("Temperature in celsius is %f", convertedTemp);
}