#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float calculateDistance(Point p1, Point p2);
int isWithinBoundary(Point p, Point bottomLeft, Point topRight);

int main() {
    Point p1 = {2, 3};
    Point p2 = {5, 7};
    Point bottomLeft = {0, 0};
    Point topRight = {10, 10};

    printf("Distance between points: %.2f\n", calculateDistance(p1, p2));
    printf("Point (2, 3) is within boundary: %s\n", isWithinBoundary(p1, bottomLeft, topRight) ? "Yes" : "No");

    return 0;
}

float calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int isWithinBoundary(Point p, Point bottomLeft, Point topRight) {
    return (p.x >= bottomLeft.x && p.x <= topRight.x &&
            p.y >= bottomLeft.y && p.y <= topRight.y);
}
