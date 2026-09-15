#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CHUNKS 512
#define FILENAME_LEN 7
typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    BYTE buffer[CHUNKS];
    FILE *img = NULL;
    char filename[FILENAME_LEN + 1];
    int jpg_count = 0;

    if (argc != 2) {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // open memory card
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    while (true) {
        // read data from memory card
        size_t result = fread(buffer, sizeof(buffer), 1, input);
        //printf("%lu\n", );

        if (result * sizeof(buffer) < CHUNKS) {
            if (jpg_count != 0) {
                fclose(img);
            }
            break;
        }

        // start of the new jpeg
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) {   // range from 0xe0 - 0xef

                // If first JPEG.   [no close older file needed]
                if (jpg_count == 0) {
                    sprintf(filename, "%03i.jpg", jpg_count);
                    jpg_count += 1;

                    img = fopen(filename, "w");
                    // write data to the file
                    fwrite(buffer, sizeof(buffer), 1, img);
                } else {

                    // close file first
                    fclose(img);
                    sprintf(filename, "%03i.jpg", jpg_count);
                    jpg_count += 1;
                    // write ###.jpg format starting with 000.jpg [dohledat]

                    // open new file
                    img = fopen(filename, "w");
                    fwrite(buffer, sizeof(buffer), 1, img);
                }

        } else {
        // JPEG already found
        if (jpg_count != 0) {
            fwrite(buffer, sizeof(buffer), 1, img);
        }

    }

    }
    fclose(input);

}

