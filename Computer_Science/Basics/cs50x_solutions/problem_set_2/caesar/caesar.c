#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void encrypt(char *message, int shift);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //if (strcmp(argv[1],"2x") == 0) {
    //    return 1;
    //}
    // try to convert argument to int and check output
    int shift = atoi(argv[1]);

    // check if argument didn't contain any characters
    int length = (shift == 0) ? 1 : (int)log10(abs(shift)) + 1;

    if (length != strlen(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (shift == 0) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("plaintext: ");
    encrypt(text, shift);
    printf("ciphertext: %s\n", text);
    return 0;
}


void encrypt(char *message, int shift) {
    while (*message) {
        if (isalpha(*message)) {
            if (isupper(*message)) {
                *message = ((*message - 'A') + shift) % 26 + 'A';
            } else {
                *message = ((*message - 'a') + shift) % 26 + 'a';
            }
        }
        message++;
    }
}

