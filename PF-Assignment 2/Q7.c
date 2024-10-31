#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	char arr[6][5];
	srand(time(0));
	char word[5];
	int score = 0;
	
	printf("Type END to repopulate the matrix\n");
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 5; j++){
			
			if(i == 5){
				if(j == 0){
					arr[i][j] = 'k';
				}
				else if(j == 1){
					arr[i][j] = '0';
				}
				else if(j == 2){
					arr[i][j] = '8';
				}
				else if(j == 3){
					arr[i][j] = '8';
				}
				else if(j == 4){
					arr[i][j] = '0';
				}
				else{
					printf("Out of bound");
				}
				//printf("%c ", arr[i][j]);
				continue;
			}
			
			char alpha = 'a' + (rand() % 26);
			arr[i][j] = alpha;
			//printf("%c ", alpha);
		}
		//printf("\n");
	}
	
	//printf("\n");
	
	do{
		printf("----------------\n\n");
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++){
				printf("%c ", arr[i][j]);
			}
			printf("\n");
		}
		
		printf("\n");
		printf("Enter a word from the matrix OR type END: ");
		fgets(word, 6, stdin);
		word[strcspn(word, "\n")] = '\0';
		
		if(strcmp(word, "END") == 0){
			for(int i = 0; i < 6; i++){
				for(int j = 0; j < 5; j++){
					
					if(i == 5){
						if(j == 0){
							arr[i][j] = 'k';
						}
						else if(j == 1){
							arr[i][j] = '0';
						}
						else if(j == 2){
							arr[i][j] = '8';
						}
						else if(j == 3){
							arr[i][j] = '8';
						}
						else if(j == 4){
							arr[i][j] = '0';
						}
						else{
							printf("Out of bound");
						}
						//printf("%c ", arr[i][j]);
						continue;
					}
					
					char alpha = 'a' + (rand() % 26);
					arr[i][j] = alpha;
					//printf("%c ", alpha);
				}
				//printf("\n");
			}
			printf("Repopulating arrays......\n\n");
			continue;
		}
		
		printf("\n");
		
		int isFound = 0;
		
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++){
				int isPresent = 1;
				
				if(j + strlen(word) < 5){
					for(int k = 0; k < strlen(word); k++){
						if(arr[i][j + k] != word[k]){
							isPresent = 0;
						}
					}
					
					if(isPresent == 1){
						printf("%s is present in row matrix from Row %d and column %d (+1) \n", word, i + 1, j + 1);
						isFound = 1;
						score++;
						break;
					}
				}
				
				
				isPresent = 1;
				
				if(i + strlen(word) < 6){
					for(int k = 0; k < strlen(word); k++){
						if(arr[i + k][j] != word[k]){
							isPresent = 0;
						}
					}
					
					if(isPresent == 1){
						printf("%s is present in column matrix from Row %d and column %d (+1) \n", word, i + 1, j + 1);
						isFound = 1;
						score++;
						break;
					}
				}
				
			}
		}
			
		if(isFound == 0){
			printf("Given word is not present in the matrix (-1)\n");
			score--;
		}
		
		//printf("Word is %s \n\n", word);
		printf("Score: %d\n", score);
	}while(1);
}