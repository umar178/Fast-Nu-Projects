#include <stdio.h>

int main() {
    int light_intensity;

    printf("Enter the light sensor value (0-1000): ");
    scanf("%d", &light_intensity);

    if (light_intensity < 0 || light_intensity > 1000) {
        printf("Invalid sensor value. Please enter a value between 0 and 1000.\n");
    } 
    else {
        if (light_intensity > 500) {
            printf("Exposed under sunshine.\n");
        } 
        else if (light_intensity >= 100 && light_intensity <= 500) {
            printf("Lighting conditions.\n");
        } 
        else if (light_intensity >= 0 && light_intensity < 100) {
            printf("Evening or low light conditions.\n");
        }
    }

    return 0;
}