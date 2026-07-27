/* Find first and last word by alphabet */
/* 
    Keep track of smallest and largest during input
    each time user inputs something, use "strcmp"
    use "strcpy" to save the word. Use "strlen" to
    determine when the user has entered a 4-letter
    word
*/


#include <stdio.h>
#include <string.h>

#define WORDS 3
#define WORD_LEN 10


int read_line(char str[], int n);

int main(void) {
    char *animals[WORDS];
    
    // create smallest and largest strings

    // ask repeatedly user for word
        // check if the word is len 4 => break
        // compare strcmp(input, smallest/largest)

    // print smallest largest


    return 0;
}


int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}

