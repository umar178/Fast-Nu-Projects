#include<stdio.h>

main(){
	int n, largest = 0, largest_c;
	
	printf("Enter numbers count: ");
	scanf("%d", &n);
	
	int arr[n];
	
	for(int i = 0; i < n; i++){
		printf("Enter element of index %d: ", i);
		scanf(" %d", &arr[i]);
	}
	
	for(int i = 0; i < n; i++){
		if(arr[i] > largest){
			largest = arr[i];
		}
	}
	
	largest_c = largest;
	//printf("Largest = %d \n\n", largest);
	
	printf("Horizontal output \n\n");
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < arr[i]; j++){
			printf("*");
		}
		printf("\n");
	}
	
	printf("\n");
	
	printf("Vertical output \n\n");
	
	
	for(int i = 0; i < largest_c; i++){
		for(int j = 0; j < n; j++){
			if(arr[j] >= largest ){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		largest--;
		printf("\n");
	}
}