#include <stdio.h>

int main() {
    int num, i, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1) {
        isPrime = 0;
    } else {
        for (i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);
        
        
    printf("Fibonacci series \n");
    int a = 0, b =1, next;
    
    for(int i = 2; i <= num; i++){
    	next = a + b;
    	printf("%d ", next);
    	a = b;
    	b = next;
	}

    return 0;
}
