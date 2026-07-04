/* 10x10 random walk */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define LEN ((int) (sizeof(arr) / sizeof(arr[0])))
#define LAST_CHAR 90
#define NUM_DIR 4

int main(void) {
   char ch[10] = {'.'};

   for (int i = 0; i < 10; i++){
    printf("%c ", ch[i]);
   }
   printf("\n");
}

// A-Z 65-90
