#include<stdio.h>

main(){
	int arr[3][3] = 
	{
		{3, 2, 1},
		{4, 5, 6},
		{9, 7, 5}	
	};
	
	for(int i = 0; i < 3; i++){
		int temp;
		
		for(int j = 0; j < 3; j++){
			if(j == 0){
				temp = arr[i][j];
				arr[i][j] = arr[i][2];
				arr[i][2] = temp;
			}
		}
	}
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}