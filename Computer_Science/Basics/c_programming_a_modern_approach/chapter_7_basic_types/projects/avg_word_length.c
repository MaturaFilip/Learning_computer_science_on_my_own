/*Enter a sentence and calculate average word length for a sentence*/
#include <stdio.h>
#include <ctype.h>


int main(void) {

    double total_let = 0.0;
    // total_wor is 1 because if else statement didn't count last word.
    int total_wor = 1;
    char ch;

    printf("Enter a sentence: ");

    ch = getchar();

    while (ch != '\n') {
        if (ch != ' ') {
            total_let += 1;
        } else {
            total_wor += 1;
        }
        ch = getchar();
    }

    printf("Average word length: %.1f\n", total_let / total_wor);

    return 0;
}