#include <stdio.h>
#include <math.h>

int main() {
    double radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    area = M_PI * radius * radius;
    printf("Area of the circle: %.2lf\n", area);

    return 0;
}
