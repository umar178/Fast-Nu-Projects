#include<stdio.h>

int even(int num){
	if(num % 2 == 0){
		return 1;
	}
	else{
		return 0;
	}
}


main(){
	int num = 3;
	
	if(even(num) == 1){
		printf("odd");
	}
	else{
		printf("Odd");
	}
}