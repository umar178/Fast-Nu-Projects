#include <stdio.h>

int main() {
    float temperature;

    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    if (temperature < 0) {
        printf("Freezing weather\n");
    } 
    else if (temperature >= 0 && temperature <= 10) {
        printf("Very cold weather\n");
    } 
    else if (temperature >= 11 && temperature <= 20) {
        printf("Cold weather\n");
    } 
    else if (temperature >= 21 && temperature <= 30) {
        printf("Normal temperature\n");
    } 
    else if (temperature >= 31 && temperature < 40) {
        printf("Hot weather\n");
    } 
    else if (temperature == 40) {
        printf("Very hot weather\n");
    } 
    else {
        printf("Temperature is above the defined range\n");
    }

    return 0;
}
