/* Caesar cipher -> enter essage and shift */
#include <stdio.h>
#include <ctype.h>



int main(void) {
    char ch;
    char message[80];
    int pointer_to_message = 0;
    int shift;

    printf("Enter message to be encrypted: ");
    while ((ch = getchar()) != '\n') {
        message[pointer_to_message] = ch;
        pointer_to_message++;
    }

    printf("\n");
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    // cipher start
    printf("\n Encrypted message: ");

    for (int i = 0; i < pointer_to_message; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                printf("%c", ((message[i] - 'A') + shift) % 26 + 'A');
            } else {
                printf("%c", ((message[i] - 'a') + shift) % 26 + 'a');
            }
        continue;
        }
        printf("%c", message[i]);
    }
    printf("\n");
    return 0;
}
