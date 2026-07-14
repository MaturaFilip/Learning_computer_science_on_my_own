#include <stdio.h>

int main(void) {
    int i = 1;
    int *p = &i;

    printf("%d\n", *p);
    printf("%d\n", &p);
    printf("%d\n", *&p);
    printf("%d\n", &*p);
    printf("%d\n", &i);
    printf("%d\n", *&i);



}