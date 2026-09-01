/*
Write a program that declares the s structure (see Section 21.4) and prints the sizes and off-
sets of the a, b, and c members. (Use sizeof to find sizes; use offsetof to find off-
sets.) Have the program print the size of the entire structure as well. From this information,
determine whether or not the structure has any holes. If it does, describe the location and
size of each.
*/

#include <stddef.h>
#include <stdio.h>

struct s {
    char a;
    int b[2];
    float c;
};

int main(void) {
    struct s stru;
    printf("char: %ld bytes\n", sizeof(stru.a));
    printf("array size: 2, int type: %ld bytes\n", sizeof(stru.b));
    printf("float: %ld bytes\n", sizeof(stru.c));
    printf("\n");
    printf("a offset = %ld byte in address structure.\n", offsetof(struct s, a));  
    printf("b offset = %ld byte in address structure.\n", offsetof(struct s, b));  
    printf("c offset = %ld byte in address structure.\n", offsetof(struct s, c));
    return 0;
}

// hole between "a" and "b" 3 bytes