#include<stdio.h>

int initializeInventory(char*** s) {
    int n;

    printf("Enter number of species: ");
    scanf("%d", &n);

    *s = (char**)malloc(sizeof(char*) * n);
    if (*s == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
	return n;
}

void addSupplies(char*** s, int n){
    printf("Enter number of supplies for species: \n");
    
    for(int i = 0; i < n; i++){
    	char buffer[100];
    	printf("Enter number of supply name for index %d: ", i);
    	scanf("%s", buffer);
    	int l = strlen(buffer) + 1;
    	(*s)[i] = (char*)malloc(sizeof(char) * l);
    	strcpy((*s)[i], buffer);
	}
	
}

void update(char*** s){
	int index;
	printf("\nEnter index number to change the supply: ");
	scanf("%d", &index);
	
	free((*s)[index]);
	
	char buffer[100];
	printf("Enter the new supply name for index %d: ", index);
	scanf("%s", buffer);
	int l = strlen(buffer) + 1;
	(*s)[index] = (char*)malloc(sizeof(char) * l);
	strcpy((*s)[index], buffer);
}

void Remove(char*** s, int *n){
	int index;
	printf("Enter index os species you want to delete: ");
	scanf("%d", &index);
	
	free((*s)[index]);
	
	for (int i = index; i < *n - 1; i++) {
        (*s)[i] = (*s)[i + 1];
    }
	
	*s = (char**)realloc(*s, sizeof(char*) * ((*n)-1));
	
	(*n)--;
}

void display(char*** s, int n){
	 printf("\nInventory:\n");
    for (int i = 0; i < n; i++) {
        printf("Species %d: %s\n", i + 1, (*s)[i]);
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
    		update(&speciesSupplies);
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