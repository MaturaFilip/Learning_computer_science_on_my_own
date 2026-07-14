/* try to print pointer address with printf() */

#include <stdio.h>

int main(void) {
    int i = 1;
    int *p = &i;

    printf("Pointer address: %p\n", p);
    return 0;
}