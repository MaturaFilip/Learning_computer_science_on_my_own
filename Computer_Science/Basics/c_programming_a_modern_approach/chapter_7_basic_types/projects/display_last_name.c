/* Enter first name and last name and display last name, comma and first letter of first name*/
#include <ctype.h>
#include <stdio.h>


int main(void) {
    char ch, first_letter;
    int flag = 0;


    printf("Enter a first and last name: ");
    ch = getchar();

    first_letter = ch;

    while (ch != '\n') {
        
        if (flag == 1) {
            printf("%c", ch);
        }

        if (ch == ' ') {
            flag = 1;
        }

        ch = getchar();
    }
    printf(", %c\n", first_letter);

    return 0;
}
