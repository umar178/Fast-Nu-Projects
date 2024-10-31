#include<stdio.h>
#include<string.h>

char *minimizedWord(char *word){
	int n = strlen(word);
	int count = 0;
	static char newWord[100];
	int j = 0;
	
	for(int i = 0; i < n; i++){
		if(i != 0 && word[i] == word[i-1]){
			continue;
		}
		newWord[j] = word[i];
		j++;
	}
	
	newWord[j] = '\0';
	
	//printf("%s", newWord);

	return newWord;
}

int main(){
	char *result = minimizedWord("coool byeeee");
	
	printf("%s", result);
}