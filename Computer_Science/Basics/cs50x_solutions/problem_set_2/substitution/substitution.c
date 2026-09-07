#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define KEY_LEN 26
#define LETTER_APPEAR_ONCE 1

void encrypt(char *message, char *key);
void check_key(char *key);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    check_key(argv[1]);

    string text = get_string("plaintext: ");


    encrypt(text, argv[1]);
    printf("ciphertext: %s\n", text);
    return 0;
}

void check_key(char *key) {
    int key_len = strlen(key);

    // check len
    if (key_len != KEY_LEN) {
        printf("Key must ocntain 26 characters.\n");
        exit(EXIT_FAILURE);
    }

    // check characters
    for (int i = 0; i < key_len; i++) {
        if (!isalpha(key[i])) {
           printf("Key must contain only characters.\n");
           exit(EXIT_FAILURE);
        }
    }

    // characters not repeated
    char a[KEY_LEN] = { 0 };
    for (int i = 0; i < key_len; i++) {
        a[toupper(key[i]) - 'A']++;
    }

    for (int i = 0; i < key_len; i++) {
        if (a[i] != LETTER_APPEAR_ONCE) {
            printf("Key letter must be unique.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void encrypt(char *message, char *key) {
    int msg_len = strlen(message);

    for (int i = 0; i < msg_len; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(key[(message[i] - 'A')]);
            } else {
                message[i] = tolower(key[(message[i] - 'a')]);
                printf("%d\n", ((message[i] - 'a')));

            }
        }
    }
}

