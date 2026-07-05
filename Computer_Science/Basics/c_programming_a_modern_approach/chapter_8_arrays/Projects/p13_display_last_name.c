/* Enter first name and last name and display last name, comma and first letter of first name*/
/* store last name to the array, not first*/
#include <ctype.h>
#include <stdio.h>


int main(void) {
    char ch, first_letter;
    int flag = 0;
    char last[20];
    int pointer = 0;


    printf("Enter a first and last name: ");
    ch = getchar();

    first_letter = ch;

    while (ch != '\n') {
        
        if (flag == 1) {
            last[pointer] = ch;
            pointer++;
        }

        if (ch == ' ') {
            flag = 1;
        }

        ch = getchar();
    }
    printf("You entered the name: ");

    for (int i = 0; i < pointer; i++) {
        printf("%c", last[i]);
    }
    printf(", %c\n", toupper(first_letter));

    return 0;
}
