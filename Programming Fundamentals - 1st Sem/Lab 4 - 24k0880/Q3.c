#include<stdio.h>

int main(){
	char c;
	
	printf("Enter a character : ");
	scanf("%c", &c);
	
	printf("ASCII value of character is %d \n", c);
	
	if(c >= 65 && c <= 90){
		printf("Capital alphabet");
	}
	else if(c >= 97 && c <= 122){
		printf("Small alphabet");
	}
	else if(c >= 48 && c <= 57){
		printf("Numeric Value");
	}
	else if(c >= 32 && c <= 127){
		printf("Special character");
	}
	else{
		printf("Not a valid character");
	}
}