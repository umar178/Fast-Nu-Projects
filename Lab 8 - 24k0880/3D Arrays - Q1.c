#include<stdio.h>

main(){
	
	int matrix[2][3][3] = 
	{
		{
			{2, 4, 6},
			{3, 5, 7},
			{1, 2, 3}
		},
		
		{
			{6, 8, 1},
			{0, 2, 7},
			{4, 9, 5}
		}
	};
	
	for(int i = 0; i < 2; i++){
		int sum  = 0;
		
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				sum += matrix[i][j][k];
			}
		}
		
		printf("sum of elements matrix %d is %d \n", i + 1, sum);
	}
	
}