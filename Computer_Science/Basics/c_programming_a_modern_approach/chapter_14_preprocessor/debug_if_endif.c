#include <stdio.h>

// when debug is NON-ZERO prints are called
// when DBEUG == 0 > prints are not called
#define DEBUG 0

int main(void) {
    #if DEBUG
    printf("print when debug is 1\n");
    printf("another debug print\n");
    #endif

    return 0;
}