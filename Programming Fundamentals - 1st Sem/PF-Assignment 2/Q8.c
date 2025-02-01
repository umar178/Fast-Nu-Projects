#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int BinToDec(int bin);
int DecToBin(int dec);
char* DecToHex(int dec);
int HexToDec(char hex[]);
char* BinToHex(int bin);
int HexToBin(char hex[]);

int main() {
    int choice, number;
    char hex[20];
    
    while (1) {
        printf("\nConversion Menu:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) { 
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                if (scanf("%d", &number) != 1) {
                    printf("Invalid binary number!\n");
                    while (getchar() != '\n');
                    continue;
                }
                printf("Decimal: %d\n", BinToDec(number));
                break;

            case 2:
                printf("Enter a decimal number: ");
                if (scanf("%d", &number) != 1) {
                    printf("Invalid decimal number!\n");
                    while (getchar() != '\n');
                    continue;
                }
                printf("Binary: %d\n", DecToBin(number));
                break;

            case 3:
                printf("Enter a decimal number: ");
                if (scanf("%d", &number) != 1) {
                    printf("Invalid decimal number!\n");
                    while (getchar() != '\n');
                    continue;
                }
                printf("Hexadecimal: %s\n", DecToHex(number));
                break;

            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                for (int i = 0; hex[i] != '\0'; i++) {
                    if (!isxdigit(hex[i])) {
                        printf("Invalid hexadecimal number!\n");
                        goto invalid_hex;
                    }
                }
                printf("Decimal: %d\n", HexToDec(hex));
                invalid_hex:
                break;

            case 5:
                printf("Enter a binary number: ");
                if (scanf("%d", &number) != 1) {
                    printf("Invalid binary number!\n");
                    while (getchar() != '\n');
                    continue;
                }
                printf("Hexadecimal: %s\n", BinToHex(number));
                break;

            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                for (int i = 0; hex[i] != '\0'; i++) {
                    if (!isxdigit(hex[i])) {
                        printf("Invalid hexadecimal number!\n");
                        goto invalid_hex2;
                    }
                }
                printf("Binary: %d\n", HexToBin(hex));
                invalid_hex2:
                break;

            case 0:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option! Please choose a number from 0 to 6.\n");
        }
    }
}

int BinToDec(int bin){
	int power = 0;
	int num = 0;
	int result = 0;
	
	while(bin > 0){
		num = (bin % 10) * pow(2, power);
		bin /= 10;
		power += 1;
		result += num;
	}
	
	return result;
}

int DecToBin(int dec) {
    int bin = 0;
    int place = 1;

    while (dec > 0) {
        bin += (dec % 2) * place;
        dec /= 2;
        place *= 10;
    }

    return bin;
}

char* DecToHex(int dec) {
    static char hex[20]; 
    int i = 0;

    if (dec == 0) {
        hex[i++] = '0';
    } else {
        while (dec > 0) {
            int remainder = dec % 16;
            hex[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
            dec /= 16;
        }
    }
    hex[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }

    return hex;
}

int HexToDec(char hex[]) {
    int dec = 0;
    int base = 1;

    for (int i = strlen(hex) - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 'A' + 10) * base;
        }
        base *= 16;
    }

    return dec;
}

char* BinToHex(int bin) {
    int dec = BinToDec(bin); 
    return DecToHex(dec);
}

int HexToBin(char hex[]) {
    int dec = HexToDec(hex); 
    return DecToBin(dec);
}