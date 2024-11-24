#include<stdio.h>

int sum(int n){
	if(n == 0){
		return;
	}
	return n%10 + sum(n/10);
}

main(){
	printf("%d", sum(123));
}