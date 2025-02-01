#include <stdio.h>
#include <string.h>

void checkPalindrome(char str[]) {
    int len = strlen(str);
    int isPalindrome = 1;

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
}

int main() {
    char words[5][20] = {"madam", "hello", "racecar", "world", "radar"};

    for (int i = 0; i < 5; i++) {
        printf("Word: %s - ", words[i]);
        checkPalindrome(words[i]);
    }

    return 0;
}
