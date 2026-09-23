#include <stdio.h>

int main() {
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;

    printf("Provide 2 points in format \"x1 y1 x2 y2\": ");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    printf("Provide 2 points in format \"x3 y3 x4 y4\": ");
    scanf("%lf %lf %lf %lf", &x3, &y3, &x4, &y4);

    double dirx1 = x2 - x1;
    double diry1 = y2 - y1;

    double dirx2 = x4 - x3;
    double diry2 = y4 - y3;

    double dot = (dirx1 * dirx2) + (diry1 * diry2);

    if (dot >= -0.0001 && dot <= 0.0001) {
        printf("Perpendicular!\n");
    } else {
        printf("NOT perpendicular.\n");
    }

    return 0;
}
