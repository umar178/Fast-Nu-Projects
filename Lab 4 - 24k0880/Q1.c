#include<stdio.h>

int main(){
	int num;
	
	scanf("%d", &num);
	
	if(num%3 == 0){
		printf("Multiple of three");
	} 
	else{
		printf("Not a Multiple of three");
	}
}