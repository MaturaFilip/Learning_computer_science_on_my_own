/* Translate an alphabetic phone number into numeric form*/
/*2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY*/

#include <stdio.h>
#include <ctype.h>

int check_char(char ch);

int main(void) {
    char ch;

    printf("Enter phone number: ");

    ch = getchar();
    while (ch != '\n') {
        if (check_char(ch) == 0) {
            printf("%c", ch);
        } else {
            printf("%d", check_char(ch));
        }
        ch = getchar();
    }
    printf("\n");
    return 0;
}

int check_char(char ch) {
    // TODO: to upper
    switch(toupper(ch)) {
        case 'A':
        case 'B':
        case 'C':
            return 2;
        
        case 'D':
        case 'E':
        case 'F':
            return 3;

        case 'G':
        case 'H':
        case 'I':
            return 4;

        case 'J':
        case 'K':
        case 'L':
            return 5;
        
        case 'M':
        case 'N':
        case 'O':
            return 6;

        case 'P':
        case 'R':
        case 'S':
            return 7;

        case 'T':
        case 'U':
        case 'V':
            return 8;

        case 'W':
        case 'X':
        case 'Y':
            return 9;
        
        default:
            return 0;
    }
}