#include <stdio.h>

void decompose(double x, long *int_part, double *frac_part);

int main(void) {
    long i;
    double f;

    printf("i after declaration: %ld,    f after declaration: %f\n", i, f);
    decompose(3.14159, &i, &f);
    printf("i after function: %ld,    f after function: %f\n", i, f);

    return 0;
}

void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long) x;
    *frac_part = x - *int_part;
}