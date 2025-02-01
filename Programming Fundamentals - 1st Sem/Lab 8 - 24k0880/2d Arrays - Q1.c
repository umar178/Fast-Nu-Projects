#include<stdio.h>

main(){
	int arr[3][3];
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("enter elemts of row %d and column %d: ", i+1, j+1);
			scanf("%d", &arr[i][j]);
			printf("\n");
		}
	}	
	
	printf("your matrix is: \n");
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}	
	
	printf("transpose of your matrix is: \n");
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}
}