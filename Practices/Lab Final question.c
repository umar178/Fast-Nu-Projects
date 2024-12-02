#include<stdio.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 1000

typedef struct{
	char str[100];
	int length;
	int s_index[3];
	int e_index[3];
}word;

void l_wrapping(char **str, int lines){
	word words[3];
	
	for(int z = 0; z < 3; z++){
		int highest_length;
		for(int i = 0; i < lines; i++){
			for(int j = 0; str[i][j] != '\0'; j++){
				int l;
				if(str[i][j] == ' '){
					for(int k = j+1; str[i][k] != ' '; k++){
						l++;
					}
				}
			}
		}
	}
	
	
}

int main(){
	FILE *f = fopen("input.txt", "r");
    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }

    char text[MAX_LINES][MAX_LINE_LENGTH];
    int line = 0;

    while (fgets(text[line], MAX_LINE_LENGTH, f) != NULL && line < MAX_LINES) {
        line++;
    }

    fclose(f);

    for (int i = 0; i < line; i++) {
        printf("Line %d: %s", i + 1, text[i]);
    }

    return 0;
}