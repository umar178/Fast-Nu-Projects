#include<stdio.h>

main(){
	char arr[3][20] = {"buy now", "save big", "limited offer"};
	
	for(int i = 0; i < 3; i++){
		printf("Word %d\n", i + 1);
		for(int j = 0; arr[i][j] != '\0'; j++){
			
			int count = 0;
			int skip = 0;
			
			for(int k = 0; k < j; k++){	
				if(arr[i][k] == arr[i][j]){
					skip = 1;
				}
			}
			if(skip == 1){
				continue;
			}
			
			
			if(arr[i][j] == ' '){
				continue;
			}
			
			for(int k = 0; arr[i][k] != '\0'; k++){	
				if(arr[i][j] == arr[i][k]){
					count++;
				}
				if(j == k){
					continue;
				}
			}
			
			printf("%c: %d \n", arr[i][j], count);
		}
	}
}