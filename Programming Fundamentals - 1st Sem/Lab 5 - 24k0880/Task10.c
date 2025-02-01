#include <stdio.h>

int main() {
    int age;
    char citizen;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Are you a citizen? (Y/N): ");
    scanf(" %c", &citizen);  // Note: A space before %c to consume any leftover newline character.

    if(age >= 18) {
        if(citizen == 'Y' || citizen == 'y') {
            printf("You are eligible to vote.\n");
        } else {
            printf("You are not eligible to vote as you are not a citizen.\n");
        }
    }
    else {
        printf("You are not eligible to vote as you are under 18.\n");
    }

    return 0;
}
