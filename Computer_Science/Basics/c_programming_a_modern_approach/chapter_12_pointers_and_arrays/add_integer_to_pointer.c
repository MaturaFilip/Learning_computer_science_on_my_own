#include <stdio.h>

int main(void) {
    int a[10], *p, *q, i;

    // 3 position
    p = &a[2];
    
    // 6 position
    q = p + 3;

    // 9 position
    p += 6;
    
    *p = 5;
    return 0;
}