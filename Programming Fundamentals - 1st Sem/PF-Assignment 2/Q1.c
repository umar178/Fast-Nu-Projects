#include<stdio.h>

main(){
	int arr[] = {0,9,4,6,5};
	
	int smallest = arr[0];
	int s_smallest = __INT_MAX__;
	
	for(int i = 0; i < 5; i++){
		if(arr[i] < smallest){
			s_smallest = smallest;
			smallest = arr[i];
		}
		else if(arr[i] > smallest && arr[i] < s_smallest){
			s_smallest = arr[i];
		}
	}
	
	printf("SECOND SMALLEST NUMBER IS %d", s_smallest);
}