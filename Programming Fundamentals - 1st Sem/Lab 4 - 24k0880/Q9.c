#include <stdio.h>

int main() {
    float fsc_marks, nts_marks;
    float fsc_percentage, nts_percentage;

    printf("Enter your F.Sc. marks (out of 1100): ");
    scanf("%f", &fsc_marks);
    printf("Enter your NTS marks (out of 100): ");
    scanf("%f", &nts_marks);

    fsc_percentage = (fsc_marks / 1100) * 100;
    nts_percentage = nts_marks;

    printf("\nYour F.Sc. Percentage: %.2f%%", fsc_percentage);
    printf("\nYour NTS Percentage: %.2f%%\n", nts_percentage);

    if (fsc_percentage > 70 && nts_percentage >= 70) {
        printf("You are eligible for IT in Oxford University.\n");
    } 
    else if (fsc_percentage > 70 && nts_percentage >= 60) {
        printf("You are eligible for Electronics in Oxford University.\n");
    } 
    else if (fsc_percentage > 70 && nts_percentage >= 50) {
        printf("You are eligible for Telecommunication in Oxford University.\n");
    } 
    else if (fsc_percentage >= 60 && fsc_percentage <= 70 && nts_percentage >= 50) {
        printf("You are eligible for IT in MIT.\n");
    } 
    else if (fsc_percentage >= 50 && fsc_percentage < 60 && nts_percentage >= 50) {
        printf("You are eligible for Chemical in MIT.\n");
    } 
    else if (fsc_percentage > 40 && fsc_percentage < 50 && nts_percentage >= 50) {
        printf("You are eligible for Computer in MIT.\n");
    } 
    else {
        printf("Sorry, you do not meet the criteria for Oxford University or MIT.\n");
    }

    return 0;
}