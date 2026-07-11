/* Implement seven-segment display */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

/* External arrays */
const int segments[10][7] =
{
		{1, 1, 1, 1, 1, 1, 0}, // 0
		{0, 1, 1, 0, 0, 0, 0}, // 1
		{1, 1, 0, 1, 1, 0, 1}, // 2
		{1, 1, 1, 1, 0, 0, 1}, // 3
		{0, 1, 1, 0, 0, 1, 1}, // 4
		{1, 0, 1, 1, 0, 1, 1}, // 5
		{1, 0, 1, 1, 1, 1, 1}, // 6
		{1, 1, 1, 0, 0, 0, 0}, // 7
		{1, 1, 1, 1, 1, 1, 1}, // 8
		{1, 1, 1, 1, 0, 1, 1}  // 9
};

char digits[4][MAX_DIGITS * 4];

int segment_coordinates[7][2] =
{
		{0, 1}, // seg 0
		{1, 2}, // seg 1
		{2, 2}, // seg 2
		{2, 1}, // seg 3
		{2, 0}, // seg 4
		{1, 0}, // seg 5
		{1, 1}  // seg 6
};

int main(void) {
    char n;
    int counter = 0;
    clear_digits_array();

    printf("Enter a number: ");
    while (counter < MAX_DIGITS) {
        n = getchar();

        if (n >= '0' && n <= '9') {
            process_digit(n - '0', counter);
            counter += 1;
        } else if (n == '\n') {
            break;
        }
    }
    print_digits_array();
    return 0;
}

void clear_digits_array(void) {
    int digits_len = MAX_DIGITS * 4;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < digits_len; j++) {
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position) {
    int row, col;
    for (int i = 0; i <= 6; i++) {
        row = segment_coordinates[i][0];
        col = segment_coordinates[i][1];

        if (segments[digit][i]) {
            digits[row][position * 4 + col] = (i % 3 == 0) ? '_' : '|';
        }
    }
}


void print_digits_array(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++) {
            printf("%c", digits[i][j]);
        }
        printf("\n");
    }
}