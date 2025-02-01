#include <stdio.h>

int main() {
	int num, sum;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 0) {
        sum += num % 10;  
        num /= 10;
    }

    printf("The single-digit sum is: %d\n", sum);
    return 0;
}