/* enter series of integers and apply selection sort */

#include <stdio.h>

void selecton_sort(int n, int a[n]);
int main(void) {
	int i, n;

	printf("Enter the number of integers you will use: ");
	scanf("%d", &n);

	int a[n];

	printf("Enter the list of numbers: ");

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);

    }
    printf("Unsorted: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    selecton_sort(n, a);
    
    printf("Sorted: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}

void selecton_sort(int n, int a[n]) {

    if (n == 0) {return;}

    int l_idx = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[l_idx]) {
            l_idx = i;
        }
    }

    int l = a[l_idx];
    a[l_idx] = a[n - 1];
    a[n - 1] = l;

    selecton_sort(n - 1, a);
}