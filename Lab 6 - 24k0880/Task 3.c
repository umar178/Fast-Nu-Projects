#include <stdio.h>

int main() {
    int pin, attempt = 0, correctPin = 1234;

    while (attempt < 3) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &pin);

        if (pin == correctPin) {
            printf("PIN accepted. Access granted.\n");
            return 0;
        } else {
            printf("Incorrect PIN. Try again.\n");
        }
        attempt++;
    }

    printf("Account locked due to too many incorrect attempts.\n");
    return 0;
}
