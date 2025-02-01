#include<stdio.h>

main(){
	int matrix1[3][3] = 
	{
		{1, 2, 3},
		{3, 5, 7},
		{5, 9, 3}	
	};
	
	int matrix2[3][3] = 
	{
		{1, 2, 3},
		{3, 5, 7},
		{5, 9, 3}	
	};
	
	int result[3][3] = 
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}