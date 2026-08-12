#include <stdio.h>
#include <stdlib.h>

// NODE
struct node {
    int value;              // data
    struct node *next;      // next node
};

// initially, the list is empty
struct node *first = NULL;

struct node *add_to_list (struct node *list, int n);
struct node *read_numbers(void);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);

int main(void) {
    
    first = add_to_list(first, 10);
    first = add_to_list(first, 20);

    return 0;
}

struct node *read_numbers(void) {
    struct node *first = NULL;
    int n;

    printf("Enter a series of integers (0 to terminate): ");
    for (;;) {
        scanf("%d", &n);
        if (n == 0) {
            return first;
        }
        first = add_to_list(first, n);
    }
}

// Add node to the list and return new node
struct node *add_to_list (struct node *list, int n) {
    struct node *new_node;
    
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = n;
    new_node->next = list;
    return new_node;
}

// "list" is a copy
struct node *search_list(struct node *list, int n) {
    for (; list != NULL; list = list->next) {
        if (list->value == n) {
            return list;
        }
    }
    return NULL;
}

// delete a node containing "n"
// if not "n" is found -> do nothing
struct node *delete_from_list(struct node *list, int n) {
    struct node *cur, *prev;

    for (cur = list, prev = NULL;
         cur != NULL && cur->value != n;
         prev = cur, cur = cur->next) {
            ;
         }
    
    if (cur == NULL) {
        return list;    // "n" not found
    }

    if (prev == NULL) {
        list = list->next;        // "n" in first node (delete first node)
    } else {
        prev->next = cur->next;  // "n" found
    }

    free(cur);      // free the space from deleted node
    return list;
}