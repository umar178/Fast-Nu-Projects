#include<stdio.h>

int firstMoveToWin(int N) {
    if (N % 5 == 0) {
        return -1;
    } else {
        return N % 5;
    }
}

int main() {
    int N;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &N);

    int result = firstMoveToWin(N);
    if (result == -1) {
        printf("It is impossible for A to guarantee a win.\n");
    } else {
        printf("A should pick %d matchstick on his first turn to guarantee a win.\n", result);
    }

    return 0;
}