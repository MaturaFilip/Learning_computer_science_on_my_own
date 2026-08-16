/* Maintains a parts database */
/* 
    - inventory array is allocated dynamically (10 part structure)
    - reallocated when it fills up (realloc - double size)
    - p (print) command calls "qsort" t sort the inventory array before it prints the parts
*/
#include <stdio.h>
#include <stdlib.h>
#include "readline.h"



#define NAME_LEN 25


    struct part {
        int number;
        char name[NAME_LEN + 1];
        int on_hand;
        double price;
    };

int find_part(int number, const struct part inventory[], int num_parts);
void insert(struct part inventory[], int *num_parts);
void search(struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);
void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);
void update_price(struct part inventory[], int num_parts);
int compare(const void *a, const void *b);

// Ask user for operation code, perform and ask again. q = quit, 
// illegal command = error

// global variables to track capacity
// size of an array is track by num_parts;
int capacity = 2;


int main(void) {
    char code;

    struct part *inventory = malloc(sizeof(struct part) * capacity);
    if (inventory == NULL) {
        printf("No allocated memory during inventory allocation. Terminating\n");
        exit(EXIT_FAILURE);
    }

    int num_parts = 0; // number of parts currently stored

    for(;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);

        while(getchar() != '\n') {  // skips to end of line
            ;
        }

        switch (code) {
            case 'i': insert(inventory, &num_parts);
                      break;
            case 's': search(inventory, num_parts);
                      break;
            case 'u': update(inventory, num_parts);
                      break;
            case 'p': print(inventory, num_parts);
                      break;
            case 't': update_price(inventory, num_parts);
                      break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");

        if (num_parts == capacity) {
            printf("Database is full capacity: %d. doubling the size to: %d\n", capacity, capacity * 2);
            int new_capacity = capacity * 2;
            // safe reallocation with temp pointer
            struct part *temp = realloc(inventory, sizeof(*temp) * new_capacity);

            if (temp == NULL) {
                printf("Reallocating failed\n");
                free(inventory);
                exit(EXIT_FAILURE);
            }
        inventory = temp;
        capacity = new_capacity;
        }
    }
    
}

// looks for index in inventory array. If part not found: return -1
int find_part(int number, const struct part inventory[], int num_parts) {
    int i;

    for (i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            return i;
        }
    }
    return -1;
}

// Prompts the user about part information
// If database is full > prints an error and returns
void insert(struct part inventory[], int *num_parts) {
    int part_number;
    double item_price;



    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number, inventory, *num_parts) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;
    
    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);

    printf("Enter price of the item: ");
    scanf("%lf", &inventory[*num_parts].price);

    // DEREFERENCE before increasing the value by 1
    (*num_parts)++;
}

// ask user for part number, show the information about the part
// if part not found > print error message
void search(struct part inventory[], int num_parts) {
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory, num_parts);

    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price: %.2lf\n", inventory[i].price);
    } else {
        printf("Part not found.\n");
    }
}

// ask user for part number and for the change in quantity > then change it
void update(struct part inventory[], int num_parts) {
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory, num_parts);

    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

void update_price(struct part inventory[], int num_parts) {
    int i, number;
    double change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory, num_parts);

    if (i >= 0) {
        printf("Enter new price tag ");
        scanf("%lf", &change);
        inventory[i].price = change;
    } else {
        printf("Part not found.\n");
    }
}

// Prints all parts in the database
void print(struct part inventory[], int num_parts) {
    int i;
    qsort(inventory, (num_parts), sizeof(inventory[0]), compare);

    printf("Part Number     Part Name                   Quantity on Hand        Price\n");

    for ( i = 0; i < num_parts; i++) {
        printf("%7d             %-25s%11d%17.2lf\n", inventory[i].number, inventory[i].name, inventory[i].on_hand, inventory[i].price);
    }
}


int compare(const void *a, const void *b) {
    return ((struct part*)a)->number -
           ((struct part*)b)->number;
}

// quicksort call
void quicksort(int a[], int *low, int *high)
{
    int *middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

// set pivot and rearange the array in way that pivot is 
// in the middle of the array/sub-array, lower values to
// the left of the array and higher value in the right side
int *split(int a[], int *low, int *high)
{
    int part_element = *low;

    for (;;)
    {
        while (low < high && part_element <= *high) {
            high--;
        }
        if (low >= high) {
            break;
        }
        *low++ = *high;


        while (low < high && *low <= part_element) {
            low++;
        }
        if (low >= high) {
            break;
        }
        *high-- = *low;
    }

    *high = part_element;
    return high;
}