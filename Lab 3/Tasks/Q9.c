#include<stdio.h>

int main(){
	float length, width, per;
	
	printf("Enter length : ");
	scanf("%f", &length);
	
	printf("Enter width : ");
	scanf("%f", &width);
	
	per = 2 * (length + width);
	
	printf("Perimeter is %f", per);
}