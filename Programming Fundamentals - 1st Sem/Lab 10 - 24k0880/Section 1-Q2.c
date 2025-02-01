#include<stdio.h>

void reverse(char *str, int l){
	if(l >= 0){
		printf("%c", str[l]);
		reverse(str, l-1);
	}
}

main(){
	reverse("hello", 5);
}