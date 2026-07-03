
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    bool weekend[7] = {true, true, true, false};

    for (int i = 0; i < 7; i++) {
        printf("%d", weekend[i]);
    }

    return 0;
}