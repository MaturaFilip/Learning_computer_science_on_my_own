#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<unistd.h>

int main(void) {
    size_t bytes = (size_t)1024 * 1024 * 1024;
    uint8_t *ptr = (uint8_t *)malloc(bytes);

    // Always check if allocation succeeded
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Successfully allocated 1 GB of RAM.\n");
    sleep(10);
    free(ptr);
    return 0;
}