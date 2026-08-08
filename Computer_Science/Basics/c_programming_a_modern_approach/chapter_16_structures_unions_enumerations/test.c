#include <stdio.h>

    typedef struct Complex {
        double real;
        double imaginary;
        } Complex;

Complex make_complex(double real, double imaginary);
Complex add_complex(Complex a, Complex b);

int main(void) {
    Complex x = make_complex(1.0, 2.0);
    Complex y = make_complex(1.0, 2.0);

    printf("%lf - %lf\n", x.real, x.imaginary);

    Complex z = add_complex(x, y);
    printf("%lf - %lf\n", z.real, z.imaginary);
    return 0;
}

Complex make_complex(double real, double imaginary) {
    Complex p;

    p.real = real;
    p.imaginary = imaginary;
    return p;
}

Complex add_complex(Complex a, Complex b) {
    Complex p;

    p.real = a.real + b.real;
    p.imaginary = a.imaginary + b.imaginary;
    return p;
}
