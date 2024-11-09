#include <stdio.h>
#include <string.h>

void encryptMessage(char message[], int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] + shift;
    }
}

void decryptMessage(char message[], int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] - shift;
    }
}

int main() {
    char message[100];
    int shift;

    printf("Enter a message: ");
    fgets(message, 100, stdin);
    printf("Enter shift amount: ");
    scanf("%d", &shift);

    encryptMessage(message, shift);
    printf("Encrypted message: %s\n", message);

    decryptMessage(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}
