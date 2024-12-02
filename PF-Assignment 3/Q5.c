#include<stdio.h>

int initializeInventory(char**** s) {
    int n;

    printf("Enter number of species: ");
    scanf("%d", &n);

    *s = (char***)malloc(sizeof(char**) * n);
    if (*s == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
	return n;
}

void addSupplies(char*** s, int n){
    printf("Enter number of supplies for species: \n");
    
    for(int i = 0; i < n; i++){
    	int s_num;
    	printf("Enter number of supplies for species number %d: ", i+1);
    	scanf("%d", &s_num);
    	s[i] = (char**)malloc(sizeof(char*) * s_num);
    	
    	for(int j = 0; j < s_num; j++){
    		char buffer[100];
            printf("Enter supply name for species %d, supply %d: ", i + 1, j + 1);
            scanf("%s", buffer);
	    	int l = strlen(buffer) + 1;
	    	s[i][j] = (char*)malloc(sizeof(char) * l);
	    	strcpy(s[i][j], buffer);
		}
	}	
}

void update(char*** s, int speciesCount) {
    int speciesIndex, supplyIndex;
    printf("\nEnter the species index to update: ");
    scanf("%d", &speciesIndex);

    if (speciesIndex < 0 || speciesIndex >= speciesCount) {
        printf("Invalid species index.\n");
        return;
    }

    int supplyCount = 0;
    while (s[speciesIndex][supplyCount] != NULL) {
        supplyCount++;
    }

    printf("\nEnter the supply index to update (0 to %d): ", supplyCount - 1);
    scanf("%d", &supplyIndex);

    if (supplyIndex < 0 || supplyIndex >= supplyCount) {
        printf("Invalid supply index.\n");
        return;
    }

    free(s[speciesIndex][supplyIndex]);

    char buffer[100];
    printf("Enter the new supply name for species %d, supply %d: ", speciesIndex + 1, supplyIndex + 1);
    scanf("%s", buffer);
    int l = strlen(buffer) + 1;

    s[speciesIndex][supplyIndex] = (char*)malloc(sizeof(char) * l);
    if (!s[speciesIndex][supplyIndex]) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(s[speciesIndex][supplyIndex], buffer);
}

void Remove(char**** s, int* speciesCount) {
    int speciesIndex;
    printf("Enter the index of the species you want to delete: ");
    scanf("%d", &speciesIndex);

    if (speciesIndex < 0 || speciesIndex >= *speciesCount) {
        printf("Invalid species index.\n");
        return;
    }

    int supplyCount = 0;
    while ((*s)[speciesIndex][supplyCount] != NULL) {
        free((*s)[speciesIndex][supplyCount]);
        supplyCount++;
    }

    free((*s)[speciesIndex]);

    for (int i = speciesIndex; i < *speciesCount - 1; i++) {
        (*s)[i] = (*s)[i + 1];
    }

    *s = (char***)realloc(*s, sizeof(char**) * (*speciesCount - 1));
    if (*s == NULL && (*speciesCount - 1) > 0) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }

    (*speciesCount)--;
}

void display(char*** s, int n) {
    printf("\nInventory:\n");
    for (int i = 0; i < n; i++) {
        printf("Species %d:\n", i + 1);
        int j = 0;
        while (s[i][j] != NULL) {
            printf("  Supply %d: %s\n", j + 1, s[i][j]);
            j++;
        }
    }
}

int main() {
    char** speciesSupplies = NULL;

    int n = initializeInventory(&speciesSupplies);
	
	addSupplies(&speciesSupplies, n);
	
    // this section is for editing purpose
    
    int choice;
    do{
    	printf("\n1: Update supplies\n");
    	printf("2: Remove species\n");
    	printf("3: Display all\n");
    	printf("4: Exit\n\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);
    	
    	if(choice == 1){
    		update(&speciesSupplies, n);
		}
		else if(choice == 2){
			Remove(&speciesSupplies, &n);
		}
		else if(choice == 3){
			display(&speciesSupplies, n);
		}
		else{
			break;
		}
    	
	}while(1);
    
    // ends here
	
    free(speciesSupplies);

    return 0;
}