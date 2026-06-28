#include <stdio.h>
#include <cs50.h>

int is_above_ten(int digit);
void validity(int card_type_digit, int check_sum, int card_length);

int main(void) {
    long number;
    long digit;
    int check_sum = 0;
    int card_type_digit;
    int card_length = 0;

    do {
        number = get_long("Number: ");
    } while(number <= 0);

    // switch
    int switcher = 0;

    while (number > 0) {

        // get first two digits
        while (number < 100 && number >= 10) {
            card_type_digit = number;
            break;
        }

        // get last number
        digit = number % 10;

        // remove last number
        number /= 10;

        card_length += 1;

        if (switcher == 0) {
            check_sum += digit;
            switcher = 1;
        } else {
            // check if the product is above 10, if so, separate them befor adding the to counter (11 -> counter += 1, counter += 1)
            int checked_num = is_above_ten(digit * 2);
            check_sum += checked_num;
            switcher = 0;
        }

    }
    // check validity
    validity(card_type_digit, check_sum, card_length);
}


/*
Helper functions
*/

int is_above_ten(int digit) {
    int sum = 0;

    if (digit >= 10) {
        sum += digit / 10;
        sum += digit % 10;
        return sum;
    }
    return digit;
}

void validity(int card_type_digit, int check_sum, int card_length) {

    if ((check_sum % 10) != 0) {
        printf("INVALID\n");
        return;
    }

    if (card_type_digit >= 51 && card_type_digit <= 55 && card_length == 16) {
        printf("MASTERCARD\n");
    } else if ((card_type_digit == 34 || card_type_digit == 37) && card_length == 15) {
        printf("AMEX\n");
    } else if (card_type_digit >= 40 && card_type_digit < 50 && (card_length == 13 || card_length == 16)) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }

}

