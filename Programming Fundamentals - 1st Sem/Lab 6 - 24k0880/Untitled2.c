#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; ++i)
        if (num % i == 0)
            return 0;
    return 1;
}

void printFibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci series: %d %d", a, b);

    for (int i = 3; i <= n; ++i) {
        next = a + b;
        a = b;
        b = next;
        printf(" %d", next);
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
        printFibonacci(num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}
