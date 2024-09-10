#include <stdio.h>

int main() {
    int hour;

    printf("Enter the time in 24-hour format (0-24): ");
    scanf("%d", &hour);

    if (hour >= 0 && hour <= 24) {
        if (hour >= 5 && hour <= 11) {
            printf("Good Morning\n");
        } else if (hour >= 12 && hour <= 17) {
            printf("Good Evening\n");
        } else if (hour >= 18 && hour <= 24) {
            printf("Good Night\n");
        } else {
            printf("It's late night or early morning. Get some rest!\n");
        }
    } else {
        printf("Invalid time. Please enter a time between 0 and 24.\n");
    }

    return 0;
}