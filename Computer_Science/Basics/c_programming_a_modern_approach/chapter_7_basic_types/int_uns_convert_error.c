/* signed operand is converted to unsigned when comparing with unsigned - it can cause funny errors*/

#include <stdio.h>

int main(void) {
    unsigned u = 10;
    int i = -10;

    if (i < u) {
        printf("i (-10) is less than u (10)\n");
    } else {
        printf("u (10) is less than i (-10)\n");
    }
}