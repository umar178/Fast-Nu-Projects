#include<stdio.h>

int main(){
	float y1 = 4, y2 = 2;
	float x1 = 5, x2 = 3;
	float slope;
	
	slope = (y2 - y1)/(x2 - x1);
	
	printf("The slope is %.3f", slope);
}