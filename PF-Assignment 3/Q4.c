#include<stdio.h>

typedef struct employee{
	int **rating;
	int score;
}employee;

void inputEmployees(int** ratings, int numEmployees, int numPeriods){
	printf("\nFill the data for employees\' rating (0-10):\n");
	for(int i = 0; i < numEmployees; i++){
		printf("\nEmployee %d:\n ", i+1);
		for(int j = 0; j < numPeriods; j++){
			do{
				printf("Evaluation number %d: ", j+1);
				scanf("%d", &ratings[i][j]);
				
				if(ratings[i][j] < 0 || ratings[i][j] > 10){
					printf("Please Enter a valid number\n");
				}
				
			}while(ratings[i][j] < 0 || ratings[i][j] > 10);
		}
	}
}

void displayPerformance(int** ratings, int numEmployees, int numPeriods){
	printf("\nData for all employees:\n");
	for(int i = 0; i < numEmployees; i++){
		printf("\nEmployee %d:\n ", i+1);
		for(int j = 0; j < numPeriods; j++){
			printf("Evaluation %d: %d\n", j+1, ratings[i][j]);
		}
	}
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods){
	int index = 0, value = 0;
	
	for(int i = 0; i < numEmployees ; i++){
		int total = 0;
		for(int j = 0; j < numPeriods; j++){
			total += ratings[i][j];
		}
		if(total > value){
			index = i;
			value = total;
		}
	}
	
	return index;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods){
	int index = 0, value = 0;
	
	for(int i = 0; i < numPeriods; i++){
		int total = 0;
		for(int j = 0; j < numEmployees; j++){
			total += ratings[j][i];
		}
		if(total > value){
			index = i;
			value = total;
		}
	}
	
	return index;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods){
	int index = 0, value = ratings[0][0];
	
	for(int i = 0; i < numPeriods; i++){
		int total = 0;
		for(int j = 0; j < numEmployees; j++){
			total += ratings[j][i];
		}
		if(total < value){
			index = i;
			value = total;
		}
	}
	
	return index;
}

main(){
	int **ratings;
	int row, col;
	
	printf("Enter number of employees: ");
	scanf("%d", &row);
	printf("Enter number of evaluations: ");
	scanf("%d", &col);
	
	ratings = (int**)malloc(sizeof(int*) * row);
	
	for(int i = 0; i < row; i++){
		ratings[i] = (int*)malloc(sizeof(int) * col);
	}
	
	inputEmployees(ratings, row, col);
	displayPerformance(ratings, row, col);
	printf("\nEmployee of the year is at index %d.", findEmployeeOfTheYear(ratings, row, col));
	printf("\nEvaluation period with the highest average rating across all employees is at index %d.", findHighestRatedPeriod(ratings, row, col));
	printf("\nEvaluation period with the worst average rating across all employees is at index %d.", findWorstPerformingEmployee(ratings, row, col));
	
	free(ratings);
}