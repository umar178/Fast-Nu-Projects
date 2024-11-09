#include <stdio.h>
#include <time.h>

int calculateFine(int dueDay, int dueMonth, int dueYear, int returnDay, int returnMonth, int returnYear) {
    struct tm due = {0};
    struct tm returned = {0};
    
    due.tm_mday = dueDay;
    due.tm_mon = dueMonth - 1; 
    due.tm_year = dueYear - 1900; 

    returned.tm_mday = returnDay;
    returned.tm_mon = returnMonth - 1;
    returned.tm_year = returnYear - 1900;

    time_t due_time = mktime(&due);
    time_t return_time = mktime(&returned);
    double seconds = difftime(return_time, due_time);
    int days = seconds / (60 * 60 * 24);
    return days > 0 ? days * 2 : 0;
}

int main() {
    int dueDay = 1, dueMonth = 10, dueYear = 2024;
    int returnDay = 15, returnMonth = 10, returnYear = 2024;

    int fine = calculateFine(dueDay, dueMonth, dueYear, returnDay, returnMonth, returnYear);
    printf("Total fine: $%d\n", fine);
    return 0;
}
