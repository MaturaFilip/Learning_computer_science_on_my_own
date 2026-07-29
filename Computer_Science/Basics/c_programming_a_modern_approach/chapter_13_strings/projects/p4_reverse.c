/*
    Echoes command-line arguments in reverse order.
    Input: reverse void and null
    Output: null and void
*/

#include <stdio.h>
int main(int argc, char *argv[]) {
    for (int i = argc - 1; i > 0; i--) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}