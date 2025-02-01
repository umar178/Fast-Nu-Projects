#include<stdio.h>

main(){
	int arr[3][3] =
	{
		{1, 2, 3},
		{4, 5, 3},
		{2, 6, 1}	
	};
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int col = 1, row = 1;
			
			for(int k = 0; k < 3; k++){
				if(arr[k][j] > arr[i][j]){
					col = 0;
					break;
				}
				if(arr[i][k] < arr[i][j]){
					row = 0;
					break;
				}
			}
			
			if(col == 1 && row == 1){
				printf("%d from %d row and %d column is saddle point \n", arr[i][j], i + 1, j + 1);
			}
			
		}
	}
}