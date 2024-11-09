#include <stdio.h>
#include <string.h>

int main() {
    char dest[100], src[100];
    int n;

    printf("Enter destination string: ");
    gets(dest);
    printf("Enter source string: ");
    gets(src);
    printf("Enter number of characters to append: ");
    scanf("%d", &n);

    strncat(dest, src, n);

    printf("New concatenated string: %s\n", dest);
    return 0;
}
