#include <stdio.h>

int main(void) {
    int a[10], *p, *q, i;

    // 9 position
    p = &a[8];
    
    // 6 position
    q = p - 3;

    // 3 position
    p -= 6;
    

    return 0;
}