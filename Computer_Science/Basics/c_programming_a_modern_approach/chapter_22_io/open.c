#include <stdio.h>
#include <stdlib.h>

#define F_NAME "file_to_open.txt"
int main(void) {

    FILE* fp;
    if ((fp = fopen(F_NAME, "r")) == NULL) {
        printf("Can't open %s\n", F_NAME);
        exit(EXIT_FAILURE);
    }

    (void)fclose(fp);
    return 0;
}