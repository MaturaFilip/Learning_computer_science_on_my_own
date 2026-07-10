#include <stdio.h>

void f(void);

int main(void) {
    f();    // i = 1
    printf("\n");
    f();    // i retains it's value -> 2

    // try to reach "i"
    //printf("%d\n", i);    -> not working (WE HIDE DATA FROM OTHER FUNCTIONS, BUT RETAIN IT FOR FUTURE CALLS OF THE SAME FUNCTION)
    return 0;
}

void f(void) {
    static int i;
    i++;
    printf("%d\n", i);  
}