#include<stdio.h>

int main(){
	float distance = 1207, forwardTrip = 118, backwardTrip = 123;
	float forwardCost, backwardCost;
	float Consumption;
	float carAverage;
	
	printf("Enter your car average: ");
	scanf("%f", &carAverage);
	
	if(carAverage < 0){
		printf("Invalid car average.");
	}
	
	Consumption =  distance/carAverage; 
	
	forwardCost = Consumption * forwardTrip;
	backwardCost = Consumption * backwardTrip;
	
	printf("Total fuel consumption over the trip is %f \n ", Consumption * 2);
	printf("Fuel cost for forward trip is %f \n", forwardCost);
	printf("Fuel cost for backward trip is %f \n", backwardCost);
}