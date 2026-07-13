/* Use pointer with <const> it can speed up function when we don't need to modify the varable */

#include <stdio.h>

void const_point(const int *p);
void value_print(int i);
int main(void) {
    int i = 2147483640;

    //const_point(&i);
    value_print(i);
    return 0;
}

void const_point(const int *p) {
    printf("i = %d\n", *p);
}

void value_print(int i) {
    printf("i = %d\n", i);
}
