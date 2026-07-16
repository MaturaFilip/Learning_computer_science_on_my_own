/* User enter fraction and program will reduce it */

#include <stdio.h>

void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
int gcd(int m, int n);

int main(void) {
    int numerator, denominator, reduced_numerator, reduced_denominator;

    printf("Enter fraction: (e.g. 10/20) ");
    scanf(" %d/%d", &numerator, &denominator);
    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
    printf("Reduced: %d/%d\n", reduced_numerator, reduced_denominator);


    return 0;
}

void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
    int g = gcd(numerator, denominator);
    *reduced_numerator = numerator / g;
    *reduced_denominator = denominator / g;
}

int gcd(int m, int n) {
    return n == 0 ? m : gcd(n, m % n);
}