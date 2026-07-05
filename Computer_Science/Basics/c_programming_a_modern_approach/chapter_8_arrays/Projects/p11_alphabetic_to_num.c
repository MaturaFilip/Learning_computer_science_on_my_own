/* Translate an alphabetic phone number into numeric form -> Before printing the translation, save it to array of char*/
/*2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY*/

#include <stdio.h>
#include <ctype.h>

char check_char(char ch);

int main(void) {
    char ch;
    int arr[15];
    int point_to_arr = 0;
    printf("Enter phone number: ");

    ch = getchar();
    while (ch != '\n') {

        if (check_char(ch) == '0') {
            arr[point_to_arr] = ch;
            point_to_arr++;

        } else {
            arr[point_to_arr] =  check_char(ch);
            point_to_arr++;
        }
        ch = getchar();
    }

    for (int i = 0; i < point_to_arr; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
    return 0;
}

char check_char(char ch) {
    // TODO: to upper
    switch(toupper(ch)) {
        case 'A':
        case 'B':
        case 'C':
            return '2';
        
        case 'D':
        case 'E':
        case 'F':
            return '3';

        case 'G':
        case 'H':
        case 'I':
            return '4';

        case 'J':
        case 'K':
        case 'L':
            return '5';
        
        case 'M':
        case 'N':
        case 'O':
            return '6';

        case 'P':
        case 'R':
        case 'S':
            return '7';

        case 'T':
        case 'U':
        case 'V':
            return '8';

        case 'W':
        case 'X':
        case 'Y':
            return '9';
        
        default:
            return '0';
    }
}