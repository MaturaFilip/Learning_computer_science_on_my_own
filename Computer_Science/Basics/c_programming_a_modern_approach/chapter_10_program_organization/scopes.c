#include <stdio.h>

int i;

void f(int i);
void g(void);
void h(void);

int main(void) {
    printf("%d\n", i);

    f(i);
    printf("i after f(i) = %d\n", i);

    g();
    printf("i after g() = %d\n", i);

    h();
    printf("i after h() = %d\n", i);


}

void f(int i) {
    i = 1;
    printf("%d\n", i);
}

void g(void) {
    int i = 2;
    printf("%d\n", i);
    if (i > 0) {
        int i;
        i = 3;
        printf("%d\n", i );
    i = 4;
    printf("%d\n", i);
    }
}

void h(void) {
    i = 5;
    printf("%d\n", i);
}