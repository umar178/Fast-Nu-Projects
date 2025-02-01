#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(num > 0) {
        printf("%d is a positive number.\n", num);

        if(num % 2 == 0) {
            printf("It is an even number.\n");
        } else {
            printf("It is an odd number.\n");
        }
    }
    else if(num < 0) {
        printf("%d is a negative number.\n", num);
    }
    else {
        printf("The number is zero.\n");
    }

    return 0;
}
