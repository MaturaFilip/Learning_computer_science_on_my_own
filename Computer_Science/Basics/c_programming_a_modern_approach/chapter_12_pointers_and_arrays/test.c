#include <stdio.h>

int main() {
    // A 2D array: 3 rows, 4 columns
    int arr[3][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120}
    };

    printf("--- ROW ARITHMETIC ---\n");
    printf("Address of Row 0: %p\n", (void*)arr);
    // Adding 1 to 'arr' shifts the pointer by 4 integers (16 bytes on most systems)
    printf("Address of Row 1: %p\n", (void*)(arr + 1)); 
    
    printf("\n--- ELEMENT ARITHMETIC ---\n");
    // *arr points to the first integer (10). Adding 1 moves to the next integer (20).
    printf("Value at (*arr + 1): %d\n", *(*arr + 1)); // Outputs 20
    
    printf("\n--- MIXING BOTH (How arr[i][j] works) ---\n");
    // Goal: Get to Row 1, Column 2 (Value: 70)
    // 1. (arr + 1) points to Row 1
    // 2. *(arr + 1) converts it to an integer pointer starting at Row 1
    // 3. *(arr + 1) + 2 moves 2 integers forward into Row 1
    // 4. Final * dereferences it to get the value
    int value = *(*(arr + 1) + 2);
    printf("Value at *(*(arr + 1) + 2): %d\n", value); // Outputs 70

    return 0;
}