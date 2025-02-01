#include <stdio.h>

int main() {
    int age;

    printf("Enter the person's age: ");
    scanf("%d", &age);

    if(age < 0) {
        printf("Invalid age.\n");
    }
    else if(age <= 12) {
        printf("Life stage: Child\n");
    }
    else if(age <= 19) {
        printf("Life stage: Teenager\n");
    }
    else if(age <= 59) {
        printf("Life stage: Adult\n");
    }
    else {
        printf("Life stage: Senior\n");
    }

    return 0;
}
