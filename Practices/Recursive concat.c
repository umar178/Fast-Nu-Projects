#include<stdio.h>
#include<string.h>

char *recursiveConcat(char *dest,char *src){
	if(*src=='\0')
	return dest;
	else{
		int lenght = strlen(dest);
		dest[lenght] = *src;
		dest[lenght + 1] = '\0';
		recursiveConcat(dest,src+1);
	}
	
}

int main(){
	char str1[100]="Hello, ";
	char str2[50]="World.";
	printf("%s",recursiveConcat(str1,str2));
}