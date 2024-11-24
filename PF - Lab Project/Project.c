#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_JSON_LENGTH 1024

void read_json(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Read the entire content of the file into a buffer
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *fileData = (char *)malloc(fileSize + 1);
    if (fileData == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return;
    }

    fread(fileData, 1, fileSize, file);
    fileData[fileSize] = '\0';  // Null-terminate the data
    fclose(file);

    // Parse the file data to extract the headings
    printf("\nHeadings in the file:\n");

    char *cursor = fileData;
    char *headings[100];  // To store the headings
    int headingCount = 0;

    // Extract headings by looking for keys followed by an opening `{`
    while ((cursor = strstr(cursor, "\"")) != NULL) {
        char *headingEnd = strstr(cursor + 1, "\"");
        if (headingEnd != NULL && *(headingEnd + 1) == ':' && *(headingEnd + 2) == ' ') {
            // Check if the next character after `:` is `{`
            if (*(headingEnd + 3) == '{') {
                *headingEnd = '\0';  // Temporarily terminate the heading string
                headings[headingCount++] = cursor + 1;  // Store the heading
                printf("%d. %s\n", headingCount, cursor + 1);
                cursor = headingEnd + 4;  // Move past the heading and opening `{`
            } else {
                cursor = headingEnd + 1;
            }
        } else {
            break;
        }
    }

    if (headingCount == 0) {
        printf("No headings found in the file.\n");
        free(fileData);
        return;
    }

    // Ask the user to select a heading
    int choice;
    printf("\nEnter the number of the block you want to view (1-%d): ", headingCount);
    scanf("%d", &choice);

    if (choice < 1 || choice > headingCount) {
        printf("Invalid choice!\n");
        free(fileData);
        return;
    }

    // Locate and display the corresponding block of data
    cursor = strstr(fileData, headings[choice - 1]) + strlen(headings[choice - 1]) + 3; // Move to the `{`
    if (*cursor != '{') {
        printf("Error locating the block data!\n");
        free(fileData);
        return;
    }

    char *blockEnd = cursor;
    int braceCount = 1;

    // Find the matching closing `}`
    while (braceCount > 0 && *blockEnd != '\0') {
        blockEnd++;
        if (*blockEnd == '{') braceCount++;
        if (*blockEnd == '}') braceCount--;
    }

    if (braceCount != 0) {
        printf("Malformed JSON data!\n");
        free(fileData);
        return;
    }

    blockEnd++;
    char temp = *blockEnd;  // Temporarily null-terminate the block
    *blockEnd = '\0';

    printf("\nData for the selected block:\n%s\n", cursor);
    *blockEnd = temp;  // Restore the original character

    free(fileData);
}

void write_json(const char *filename) {
    char heading[50];
    char *Data;
    int datasets, capacity = 1000;
    int track = 0;

    Data = (char *)malloc(capacity * sizeof(char));
    if (Data == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Give your block a heading (0 for none): ");
    scanf("%s", heading);

    if (strcmp(heading, "0") != 0) {
        Data[track++] = '"';
        strcpy(Data + track, heading);
        track += strlen(heading);
        Data[track++] = '"';
        Data[track++] = ':';
        Data[track++] = ' ';
    }

    Data[track++] = '{';
    Data[track++] = '\n';

    printf("Enter the number of datasets for this block: ");
    scanf("%d", &datasets);

    for (int i = 0; i < datasets; i++) {
        char key[50], value[50];
        int op;

        Data[track++] = '\t';

        printf("\nFor element %d, enter 1 for integer and 0 for string: ", i + 1);
        scanf("%d", &op);

        printf("Key: ");
        scanf("%s", key);
        Data[track++] = '"';
        strcpy(Data + track, key);
        track += strlen(key);
        Data[track++] = '"';
        Data[track++] = ':';
        Data[track++] = ' ';

        if (op == 1) {
            printf("Enter integer value: ");
            scanf("%s", value); 
            strcpy(Data + track, value);
            track += strlen(value);
        } else {
            printf("Enter string value: ");
            scanf("%s", value);
            Data[track++] = '"';
            strcpy(Data + track, value);
            track += strlen(value);
            Data[track++] = '"';
        }

        if (i < datasets - 1) {
            Data[track++] = ',';
        }
        Data[track++] = '\n';
    }

    Data[track++] = '}';
    Data[track++] = '\n';
    Data[track] = '\0'; 

    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        free(Data);
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);

    if (fileSize > 0) {
        fseek(file, -2, SEEK_END); 
        fprintf(file, ",\n%s\n}", Data);
    } else {
        fprintf(file, "{\n%s\n}", Data); 
    }

    fclose(file);

    printf("JSON-like data appended to %s:\n", filename);
    printf("%s", Data);

    free(Data);
}

int main() {
    char filename[50];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);
    
    do{
    	printf("Choose an operation:\n");
	    printf("1. Read data from file\n");
	    printf("2. Write to JSON file\n");
	    printf("3. Read raw file\n");
	    printf("4. Exit\n");
	    printf("Enter your choice: ");
	    scanf("%d", &choice);
	
	    if (choice == 1) {
	        read_json(filename);
	    } else if (choice == 2) {
	        write_json(filename);
	    } else if (choice == 3) {
	        write_json(filename);
	    } else {
	        printf("Invalid choice.\n");
	    }
	}while(choice != 4);

    

    return 0;
}
