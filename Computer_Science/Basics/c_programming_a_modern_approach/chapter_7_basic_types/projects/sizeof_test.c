/* Print the value of sizeof() function with different types*/

#include <stdio.h>



int main(void) {
    int i = 32;
    short s = 20;
    long l = 303402;
    float f = 20.1;
    double d = 33.32233;
    long double ld = 3.203938;
    char ch = 'a';

    printf("int = %ld\n", sizeof(i));
    printf("short = %ld\n", sizeof(s));
    printf("long = %ld\n", sizeof(l));
    printf("float = %ld\n", sizeof(f));
    printf("double = %ld\n", sizeof(d));
    printf("long double = %ld\n", sizeof(ld));
    printf("char = %ld\n", sizeof(ch));
    

}
