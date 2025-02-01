#include <stdio.h>

int main() {
    char character, encrypted, decrypted;
    int key = 5;  

    printf("Enter a character to encrypt: ");
    scanf("%c", &character);
    printf("Enter an encryption key: ");
    scanf("%d", &key);

    encrypted = character ^ key;
    printf("Encrypted character: %c\n", encrypted);
    printf("Encrypted ASCII value: %d\n", encrypted);

    decrypted = encrypted ^ key;
    printf("Decrypted character: %c\n", decrypted);
    printf("Decrypted ASCII value: %d\n", decrypted);

    return 0;
}
