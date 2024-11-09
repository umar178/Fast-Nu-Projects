#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_JSON_LENGTH 1024

void read_json(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Reading JSON-like content:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void write_json(const char *filename) {
    char heading[50];
    char *Data;
    int datasets;
    int capacity = 10;
    int track = 0;
    
    printf("Give your block a heading(0 for non): ");
    scanf("%s", heading);
    
    Data = (char *)malloc(datasets * capacity * sizeof(char));
    
    if(strcmp(heading, "0") != 0){
    	Data[track] = '"';
    	track++;
    	for(int i = 0; i < strlen(heading); i++){
    		Data[track] = heading[i];
    		track++;
		}
		Data[track] = '"';
		track++;
	}
	
	Data[track] = '{';
	track++;
	Data[track] = '\n';
	track++;
    //printf("%s", Data);
    
    printf("Enter amount of data sets for this block: ");
    scanf("%d", &datasets);
    
    for(int i = 0; i < datasets; i++){
    	char key[50], value[50];
    	int op;
    	printf("\n");
    	printf("For Element %d, Enter 1 for integer and 0 for string: ", i+1);
    	
    	Data[track] = '\t';
    	track++;
    	
    	if(scanf("%d", &op) == 1){
    		printf("Enter Data for Integer element %d: \n", i + 1);
    		
    		Data[track] = '"';
    		track++;
	    	printf("Key: ");
	    	scanf("%s", key);
	    	for(int j = 0; j < strlen(key); j++){
	    		Data[track] = key[j];
	    		track++;
			}
			Data[track] = '"';
    		track++;
    		
    		Data[track] = ':';
    		track++;
    		Data[track] = ' ';
    		track++;
			
	    	printf("Value: ");
	    	scanf("%s", value);
	    	for(int j = 0; j < sizeof(value); j++){
	    		Data[track] = value[j];
	    		track++;
			}
	    	
	    	track++;
		}
		else{
			printf("Enter Data for String element %d: \n", i + 1);
			
	    	printf("Key: ");
	    	scanf("%s", key);
	    	Data[track] = '"';
    		track++;
	    	for(int j = 0; j < sizeof(key); j++){
	    		Data[track] = key[j];
	    		track++;
			}
			Data[track] = '"';
    		track++;
    		
    		Data[track] = ':';
    		track++;
    		Data[track] = ' ';
    		track++;
			
			Data[track] = '"';
    		track++;
	    	printf("Value: ");
	    	scanf("%s", value);
	    	for(int j = 0; j < strlen(value); j++){
	    		Data[track] = value[j];
	    		track++;
			}
			Data[track] = '"';
    		track++;
		}
		
    	if(i < datasets){
    		Data[track] = ',';
    		track++;
    		
    		Data[track] = '\n';
    		track++;
    	}
	}
	
	printf("%s", Data);
    
	/*
    printf("Enter the key: ");
    scanf("%s", key);
    printf("Enter the value: ");
    scanf("%s", value);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }

    fprintf(file, "{\n\t\"%s\": \"%s\"\n}\n", key, value);
    fclose(file);

    printf("JSON-like data written to %s\n", filename);
    */
}

int main() {
    char filename[50];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Choose an operation:\n");
    printf("1. Read JSON-like data\n");
    printf("2. Write JSON-like data\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        read_json(filename);
    } else if (choice == 2) {
        write_json(filename);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
