#include <stdio.h>

void g(void);
int a;

int main(void) {
    printf("%d\n", a);
    g();
    return 0;
}

void g(void) {
    int d;
    d = 2;
    printf("%d - %d\n", a, d);
    {
    int e;
    e = 3;
    printf("%d\n", e);
    printf("%d\n", d);  // d is still visible
    }

    // the "e" is not visible from here

}