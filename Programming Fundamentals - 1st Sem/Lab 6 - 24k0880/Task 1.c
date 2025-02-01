#include <stdio.h>

int main() {
    int num, sum = 0;

    // Use a do-while loop to ensure the code executes at least once
    do {
        printf("Enter a number (enter 0 to stop): ");
        scanf("%d", &num);
        sum += num;
        printf("Current sum: %d\n", sum);
    } while (num != 0);  // Continue until user enters 0

    printf("Final sum: %d\n", sum);
    return 0;
}
