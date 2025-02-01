#include<stdio.h>

int validateEmail(char* email){
	int length = strlen(email);
	printf("String length: %d\n", length);
	if(length == 0){return 0;}
	
	int f1 = 0, f2 = 0;
	
	for(int i = 0; i < length; i++){
		if(email[i] == '@' && f1 == 0){
			f1 = 1;
		}
		else if(email[i] == '@' && f1 == 1){
			return 0;
		}
		
		if(email[i] == '.' && f1 == 1){
			f2 = 1;
		}
	}
	
	if(f1 == 1 && f2 == 1){
		return 1;
	}
	else{
		return 0;
	}
}

main(){
	char temp[1000]; 
    char *email;

    printf("Enter Your email: ");
    fgets(temp, sizeof(temp), stdin);

    int length = strlen(temp);
    if (temp[length - 1] == '\n') {
        temp[length - 1] = '\0';
        length--; 
    }

    email = (char *)malloc((length + 1) * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    strcpy(email, temp);
    
	/*
    printf("You entered: %s\n", email);
    printf("String length: %d\n", length);
	*/
	
    if(validateEmail(email) == 0){
    	printf("Invalid email");
	}
	else{
		printf("Valid email");
	}
	
    free(email);
}