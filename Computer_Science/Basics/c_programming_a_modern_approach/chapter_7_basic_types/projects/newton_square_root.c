/*Enter a positive number and find square root with Newton method*/
#include <stdio.h>
#include <math.h>

int main(void) {

    int x;

    // initial guess
    double y = 1, avg_y_xy;

    printf("Enter a positive number: ");

    scanf("%d", &x);

    while (1) {
        avg_y_xy = (y + (x / y)) / 2;

        if (fabs(y - avg_y_xy) < 0.00001) {
            break;
        }

        y = avg_y_xy;
    }

    printf("Square root: %f\n", avg_y_xy);

    return 0;
}