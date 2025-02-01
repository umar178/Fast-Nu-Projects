#include <stdio.h>

void convertToKilometers(float meters);

int main() {
    float distances[] = {1000, 2000, 1500, 2500, 500};
    int size = sizeof(distances) / sizeof(distances[0]);

    for (int i = 0; i < size; i++) {
        convertToKilometers(distances[i]);
    }

    return 0;
}

void convertToKilometers(float meters) {
    static int callCount = 0;
    callCount++;

    float kilometers = meters / 1000.0;
    printf("Distance: %.2f meters = %.2f kilometers\n", meters, kilometers);
    printf("Function called %d times so far.\n", callCount);
}
