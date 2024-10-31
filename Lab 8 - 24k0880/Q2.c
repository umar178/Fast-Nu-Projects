#include<stdio.h>

main(){
	int n;
	scanf("%d", &n);
	
	for(int i = n; i > 0 ; i--){
		if(i % 2 == 1){
			printf("%d ", i);
		}
	}
}