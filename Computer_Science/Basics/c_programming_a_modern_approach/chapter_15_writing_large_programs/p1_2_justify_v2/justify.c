/* Formats a file of text */


#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void) {
    char word[MAX_WORD_LEN + 2];
    int word_len;

    // clean helper variables line[], line_len, num_words
    clear_line();

    for (;;) {

        // Read one word. E.g. "hello dog" > "hello"
        word_len = read_word(word, MAX_WORD_LEN + 1);


        if (word_len == 0) {
            // if line_len > 0, print whole adjusted line (line arr)
            flush_line();
            return 0;
        }

        // word is MAX_WORD_LEN + 1 so we can compare this and add "*" to position 21
        //if (word_len > MAX_WORD_LEN) {
            // "cut" the long word with '*'
            // after '*' is '\0' because of read_word input '+1'
        //    word[MAX_WORD_LEN] = '*';
        //}

        // if we haven't any available space in "line" arr
        if (word_len + 1 > space_remaining()) {
            // writes current line with justification
            write_line();
            // reset line[], line_len, num_words
            clear_line();
        }
        // append word to the "line" arr
        add_word(word);
    }

}