#include<stdio.h>

main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 2; i <= n; i++){
		int prime = 1;
		
		for(int j = 2; j <= i/2; j++){
			if(i % j == 0){
				prime = 0;
				break;
			}
		}
		
		if(prime == 1){
			printf("%d is a prime number in the sequence \n", i);
		}
		
	}
	
	
}