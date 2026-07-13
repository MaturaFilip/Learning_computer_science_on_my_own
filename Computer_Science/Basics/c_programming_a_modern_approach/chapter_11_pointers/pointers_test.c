#include <stdio.h>

int main(void) {
    int i;
    int *p = &i;

    printf("i after declaring: %d\n", i);
    printf("*p points to declared i: %d\n", p);
    printf("*p with indirect operator to declared i: %d\n", *p);

    i = 1;

    printf("i with value: %d\n", i);
    printf("*p points to i: %d\n", p);
    printf("*p with indirect operator to i: %d\n", *p);

    return 0;
}