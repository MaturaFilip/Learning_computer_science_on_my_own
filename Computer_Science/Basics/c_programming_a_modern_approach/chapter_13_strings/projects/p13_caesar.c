/* Caesar cipher -> enter essage and shift */

/*
    implement:
        void encrypt(char *message, int shift);

*/
#include <stdio.h>
#include <ctype.h>

#define MESSAGE_LEN 150
void encrypt(char *message, int shift);
int read_line(char str[], int n);

int main(void) {

    char ch;
    char message[MESSAGE_LEN];

    printf("Enter message to be encrypted: ");
    read_line(message, MESSAGE_LEN);

    int shift;

    printf("\n");
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    // cipher start
    printf("\nEncrypted message: ");
    encrypt(message, shift);
    printf("%s\n", message);
 
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

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}