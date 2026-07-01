/*Enter a positive number and find square root with Newton method*/
#include <stdio.h>
#include <math.h>

int main(void) {
    unsigned int x;
    unsigned int total = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &x);

    for (int i = 1; i <= x; i++) {
        total *= i;
    }

    printf("Factorial of %d: %d\n", x, total);
    return 0;
}