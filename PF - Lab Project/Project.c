#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_JSON_LENGTH 1024

typedef struct{
	char *name;
	int line;
}Block;

void remove_quotes_and_commas(char* str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != '"' && str[i] != ',' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            str[j++] = str[i]; 
        }
        i++;
    }
    str[j] = '\0';
}

void read_json(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s.\n", filename);
        return;
    }

    char str[MAX_LINE_LENGTH];
    Block *data = NULL;
    int data_i = -1;
    int l = 0;

    fgets(str, sizeof(str), file);
    l++;

    while (fgets(str, sizeof(str), file) != NULL) {
        l++;

        if (strchr(str, '{')) {
            data_i++;

            Block *temp = (Block*)realloc(data, sizeof(Block) * (data_i + 1));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(data);
                fclose(file);
                return;
            }
            data = temp;

            data[data_i].name = (char*)malloc(sizeof(char) * (strlen(str) + 1));

            sscanf(str, "%[^:]", data[data_i].name);

            data[data_i].line = l;
        }
    }
    
    printf("\nSelect a block number from the following list:\n");
    for (int i = 0; i <= data_i; i++) {
        printf("%d: %s\n", i + 1, data[i].name);
    }

    int block_number;
    printf("\nEnter the block number to view its data: ");
    scanf("%d", &block_number);

    if (block_number < 1 || block_number > data_i + 1) {
        printf("Invalid block number!\n");
        free(data);
        fclose(file);
        return;
    }

	printf("\n");
	
    fseek(file, 0, SEEK_SET); 
    l = 0;
    int block_found = 0;
    while (fgets(str, sizeof(str), file) != NULL) {
        l++;
        if (block_found) {
            if (strchr(str, '}')) {
            	printf("\n");
                printf("End of block reached.\n");
                printf("\n");
                break;
            }
            remove_quotes_and_commas(str);
            printf("%s\n", str);
        } else {
            if (strstr(str, data[block_number - 1].name)) {
                block_found = 1;
                printf("Data for block %d (%s):\n", block_number, data[block_number - 1].name);
            }
        }
    }
    
    printf("\n");

    free(data);
    fclose(file);
}

void append_json(const char *filename) {
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
    Data[track] = '\0'; 

    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Failed to create the file.\n");
            free(Data);
            return;
        }
        fprintf(file, "{\n%s\n}", Data);
    } else {
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);

        if (fileSize == 0) {
            fprintf(file, "{\n%s\n}", Data);
        } else {
            fseek(file, -2, SEEK_END); 
            fprintf(file, ",\n%s\n}", Data);
        }
    }

    fclose(file);

    printf("JSON-like data appended to %s:\n", filename);
    printf("%s", Data);

    free(Data);
}

void read_raw(const char *filename){
	FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s.\n", filename);
        return;
    }

    char str[MAX_LINE_LENGTH];
    
	printf("\n");
    printf("File Content:\n");
    
    while (fgets(str, sizeof(str), file) != NULL) {
        printf("%s", str); 
    }
	printf("\n");
	printf("\n");
    fclose(file);
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
    Data[track] = '\0';

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create or open the file.\n");
        free(Data);
        return;
    }

    fprintf(file, "{\n%s\n}", Data);

    fclose(file);

    printf("Updated values have been written to %s:\n", filename);
    printf("%s", Data);

	printf("\n");
	printf("\n");

    free(Data);
}

void update_json(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        printf("Could not open file %s.\n", filename);
        return;
    }

    char **data = NULL;
    char str[MAX_LINE_LENGTH];
    Block *data_struct = NULL;
    int data_i = -1;
    int l = 0;

    while (fgets(str, sizeof(str), file) != NULL) {
        l++;
        data = (char **)realloc(data, sizeof(char *) * l);
        if (!data) {
            fclose(file);
            return;
        }
        data[l - 1] = (char *)malloc(sizeof(char) * (strlen(str) + 1));
        if (!data[l - 1]) {
            fclose(file);
            return;
        }
        strcpy(data[l - 1], str);

        if (strchr(str, '{')) {
            data_i++;
            data_struct = (Block *)realloc(data_struct, sizeof(Block) * (data_i + 1));
            if (!data_struct) {
                fclose(file);
                return;
            }
            data_struct[data_i].name = (char *)malloc(sizeof(char) * (strlen(str) + 1));
            if (!data_struct[data_i].name) {
                fclose(file);
                return;
            }
            sscanf(str, "\"%[^\"]", data_struct[data_i].name);
            data_struct[data_i].line = l - 1;
        }
    }

    printf("\nBlocks detected:\n");
    for (int i = 1; i <= data_i; i++) {
        printf("%d: %s\n", i, data_struct[i].name);
    }

    int block_number;
    printf("\nEnter the block number to view its data: ");
    scanf("%d", &block_number);

    while (block_number < 1 || block_number > data_i + 1) {
        printf("Invalid block number!\n");
        printf("\nEnter the block number to view its data: ");
        scanf("%d", &block_number);
    }

    int block_start = data_struct[block_number].line;
    int block_end = block_start;

    for (int i = block_start + 1; i < l; i++) {
        if (strchr(data[i], '}')) {
            block_end = i;
            break;
        }
    }

    printf("Data elements:\n");
    for (int i = block_start + 1; i < block_end; i++) {
        printf("%s", data[i]);
    }

    char key[50], quoted_key[52];
    printf("Enter element key to modify: ");
    scanf("%s", key);

    snprintf(quoted_key, sizeof(quoted_key), "\"%s\"", key);

    int found = 0;
    for (int i = block_start + 1; i < block_end; i++) {
        char *key_pos = strstr(data[i], quoted_key);
        if (key_pos && key_pos[strlen(quoted_key)] == ':') {
            found = 1;

            // Determine if the value is a string or an integer
            char *value_start = strchr(key_pos, ':') + 1;
            while (*value_start == ' ' || *value_start == '\t') {
                value_start++;
            }

            if (*value_start == '"') { // String value
                char buffer[100];
                printf("Enter a string value: ");
                scanf("%s", buffer);
                snprintf(data[i], MAX_LINE_LENGTH, "\t\"%s\": \"%s\"%s\n", key, buffer, i == block_end - 1 ? "" : ",");
            } else { // Numerical value
                int value;
                printf("Enter a numerical value: ");
                scanf("%d", &value);
                snprintf(data[i], MAX_LINE_LENGTH, "\t\"%s\": %d%s\n", key, value, i == block_end - 1 ? "" : ",");
            }
            printf("Updated element: %s", data[i]);
            break;
        }
    }

    if (!found) {
        printf("Element not found in the selected block.\n");
    }

    freopen(filename, "w", file);
    for (int i = 0; i < l; i++) {
        fputs(data[i], file);
    }

    for (int i = 0; i < l; i++) {
        free(data[i]);
    }
    free(data);

    for (int i = 0; i <= data_i; i++) {
        free(data_struct[i].name);
    }
    free(data_struct);

    fclose(file);
}



int main() {
    char filename[50];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);
    
    do{
    	printf("Choose an operation:\n");
	    printf("1. Read a block of data from file\n");
	    printf("2. Append to file\n");
	    printf("3. Read raw file\n");
	    printf("4. Overwrite the complete file\n");
	    printf("5. Update values\n");
	    printf("6. Exit\n");
	    printf("Enter your choice: ");
	    scanf("%d", &choice);
	
	    if (choice == 1) {
	        read_json(filename);
	    } else if (choice == 2) {
	        append_json(filename);
	    } else if (choice == 3) {
	        read_raw(filename);
	    }else if (choice == 4) {
	        write_json(filename);
	    }else if (choice == 5) {
	        update_json(filename);
	    }else if (choice == 6) {
	        break;
	    } else {
	        printf("Invalid choice.\n");
	    }
	}while(choice != 6);

    return 0;
}
