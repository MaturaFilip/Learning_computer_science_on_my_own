/* Sums a series of numbers using long variables*/

#include <stdio.h>

int main(void) {
    float f = 20.50;
    float frac_part;
    frac_part = f - (int) f;

    printf("%f\n", (frac_part));
}