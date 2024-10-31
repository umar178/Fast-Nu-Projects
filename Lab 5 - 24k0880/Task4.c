#include <stdio.h>

int main() {
    int attendance, assignments, exam;
    float final_grade;

    printf("Enter attendance score (out of 10): ");
    scanf("%d", &attendance);

    printf("Enter assignment score (out of 30): ");
    scanf("%d", &assignments);

    printf("Enter exam score (out of 60): ");
    scanf("%d", &exam);

    final_grade = attendance + assignments + exam;

    if (final_grade >= 90) {
        printf("Final Grade: A\n");
    } else if (final_grade >= 80) {
        printf("Final Grade: B\n");
    } else if (final_grade >= 70) {
        printf("Final Grade: C\n");
    } else if (final_grade >= 60) {
        printf("Final Grade: D\n");
    } else {
        printf("Final Grade: F\n");
    }

    return 0;
}