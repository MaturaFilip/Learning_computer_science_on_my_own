#include <stdio.h>

    typedef struct Fraction {
        int numerator;
        int denominator;
        } Fraction;

Fraction reduce(Fraction x);
int gcd(int m, int n);
Fraction add_frac(Fraction a, Fraction b);
Fraction mult_frac(Fraction a, Fraction b);
Fraction sub_frac(Fraction a, Fraction b);

int main(void) {
    Fraction x = {.numerator = 2, .denominator = 3};
    Fraction y = {.numerator = 2, .denominator = 3};
    Fraction z = mult_frac(x, y);
    printf("numerator: %d, denominator %d\n", z.numerator, z.denominator);
    return 0;
}


Fraction reduce(Fraction x) {
    int g = gcd(x.numerator, x.denominator);
    Fraction z = {
        .numerator = (x.numerator / g),
        .denominator = (x.denominator / g),
    };
    return z;
}

int gcd(int m, int n) {
    return n == 0 ? m : gcd(n, m % n);
}

Fraction add_frac(Fraction a, Fraction b) {
    Fraction x = {
        .numerator = a.numerator + b.numerator,
        .denominator = a.denominator + b.denominator,
    };
    Fraction y = reduce(x);
    return y;
}

Fraction mult_frac(Fraction a, Fraction b) {
    Fraction x = {
        .numerator = a.numerator * b.numerator,
        .denominator = a.denominator * b.denominator,
    };
    Fraction y = reduce(x);
    return y;
}

Fraction sub_frac(Fraction a, Fraction b) {
    Fraction x = {
        .numerator = a.numerator - b.numerator,
        .denominator = a.denominator - b.denominator,
    };
    Fraction y = reduce(x);
    return y;
}

Fraction mult_frac(Fraction a, Fraction b) {
    if (b.numerator == 0 || b.denominator == 0) {
        Fraction x = {
            .numerator = 0,
            .denominator = 0,
        };
        Fraction y = reduce(x);
        return y;;
    }
    Fraction x = {
        .numerator = a.numerator / b.numerator,
        .denominator = a.denominator / b.denominator,
    };
    Fraction y = reduce(x);
    return y;
}