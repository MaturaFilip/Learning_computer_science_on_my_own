/*
Design a union that makes it possible to view a 32-bit value as either a float or the struc-
ture described in Exercise 14. Write a program that stores 1 in the structure’s sign field, 128
in the exponent field, and 0 in the fraction field, then prints the float value stored in the
union. (The answer should be –2.0 if you’ve set up the bit-fields correctly.)
*/

#include <stdio.h>

union {
    struct {
        float float_num;
    } float_n;
    struct {
        unsigned int fraction: 23;
        unsigned int expon: 8;
        unsigned int sign: 1;
    } ieee_float;
} flt;
    
int main()
{
    
    flt.ieee_float.sign = 1;
    flt.ieee_float.expon = 128;
    flt.ieee_float.fraction = 0;
    printf("%f\n", flt.float_n.float_num);
    return 0;
}