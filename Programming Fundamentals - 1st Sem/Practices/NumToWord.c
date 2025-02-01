#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* words[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
char* tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char* ToT[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

char* numToWord(int num) {
    if (num == 0) {
        return "Zero";  
    }
    
    char* result = (char*)malloc(1000);
    strcpy(result, ""); 
    
    int digit;
    if (num >= 1000) {
        digit = num / 1000;
        strcat(result, words[digit - 1]);
        strcat(result, " Thousand ");
        if (num % 1000 != 0) {
            strcat(result, numToWord(num % 1000));
        }
    } else if (num >= 100) {
        digit = num / 100;
        strcat(result, words[digit - 1]);
        strcat(result, " Hundred ");
        if (num % 100 != 0) {
            strcat(result, numToWord(num % 100));
        }
    } else if (num >= 20) {
        digit = num / 10;
        strcat(result, tens[digit - 2]);
        strcat(result, " ");
        if (num % 10 != 0) {
            strcat(result, numToWord(num % 10));
        }
    } else if (num >= 10) {
        strcat(result, ToT[num - 10]);
    } else {
        strcat(result, words[num - 1]);
    }
    
    return result;
}

int main() {
    int number = 1234;
    char* result = numToWord(number);
    printf("%s\n", result);
    free(result);
    return 0;
}
