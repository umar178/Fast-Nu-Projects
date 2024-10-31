#include <stdio.h>

int main() {
    char name[16];
    char email[31];
    char phone[16];
    int validName = 0;
    int validEmail = 0;
    int validNum = 0;

    printf("Enter name (15 characters max): ");
    scanf("%15s", name);
    
    printf("Enter email (30 characters max): ");
    scanf("%30s", email);
    
    printf("Enter phone number (15 characters max): ");
    scanf("%15s", phone); 

    printf("\n");

    // Validate name input
    for (int i = 0; name[i] != '\0'; i++) {
        if ((name[i] < 'A' || name[i] > 'Z') && 
            (name[i] < 'a' || name[i] > 'z') && 
            name[i] != ' ') {
            printf("Invalid name\n");
            validName = 1;
            break; 
        }
    }

    for (int i = 0; email[i] != '\0'; i++) {
        if ((email[i] < 'A' || email[i] > 'Z') &&
            (email[i] < 'a' || email[i] > 'z') &&
            (email[i] < '0' || email[i] > '9') &&
            (email[i] != '.') &&
            (email[i] != '_') &&                     
            (email[i] != '-') &&
            (email[i] != '@')) { 
            printf("Invalid Email \n");
            validEmail = 1;
            break; 
        }
        if (email[i] == '@') {
            validEmail = 1; 
        }
    }

    if (validEmail == 0) {
        printf("Invalid Email. Does not contain '@'\n");
    }
    else{
    	printf("valid Email.\n");
	}

	for (int i = 0; phone[i] != '\0'; i++) {
        if ((phone[i] < '0' || phone[i] > '9') &&                   
            (phone[i] != '-') &&
            (phone[i] != ' ') &&
            (phone[i] != '+')) { 
            printf("Invalid phone \n");
            validNum = 1;
            break; 
        }
        if(i != 0 && phone[i] == '+'){
        	printf("Invalid Number. + sign at wrong place");
        	validNum = 1;
        	break;
		}
    }
    
    if (validNum == 0) {
        printf("Valid phone Num");
    }
    
/*
    printf("Valid Name: %s\n", name);
    printf("Valid Email: %s\n", email);
    printf("Phone Number: %s\n", phone);
*/

    return 0;
}
