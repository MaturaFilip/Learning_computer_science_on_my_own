/*
    two command line arguments: int_a, int_b
    sum the inputs
*/

#include <stdio.h>
int main(int argc, char *argv[]) {
    int sum = 0;
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }
    printf("Total: %d\n", sum);
    return 0;
}