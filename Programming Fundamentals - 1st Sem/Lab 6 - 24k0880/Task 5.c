#include <stdio.h>

int main() {
    int num, reversed = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    do {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    } while (num != 0);

    printf("Reversed number: %d\n", reversed);
    return 0;
}
