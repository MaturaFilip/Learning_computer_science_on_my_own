#include <stdio.h>
#include <stdlib.h>

int *find_largest(int n, int a[n]);

int main(void) {
    int n = 5;
    int a[5] = {1, 2, 3, 4, 5};

    int *p = find_largest(n, a);
    printf("Lergest num: %d\n", *p);

    return 0;
}

int *find_largest(int n, int a[n]) {
    int val = a[0];
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > val) {
            val = a[i];
            idx = i;
        }
    }
    return &a[idx];
}