#include <stdio.h>

int main() {
    int age;
    float income;
    int credit_score;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your monthly income in RS: ");
    scanf("%f", &income);

    printf("Enter your credit score: ");
    scanf("%d", &credit_score);

    if (age >= 18 && age <= 60 && income >= 100000 && credit_score >= 700) {
        printf("You are eligible for a loan.\n");
    } else {
        printf("You are not eligible for a loan.\n");
    }

    return 0;
}
