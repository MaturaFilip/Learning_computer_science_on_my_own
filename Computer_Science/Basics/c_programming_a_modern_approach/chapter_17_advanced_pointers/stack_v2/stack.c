#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;              // data
    struct node *next;      // next node
};

// initially, the list is empty
struct node *first = NULL;

void make_empty(void);
bool is_empty(void);
bool push(int n);
int pop(void);
// HELPER FUNCTIONS
struct node *delete_all(struct node *list);

int main(void) {

    push(10);
    push(20);
    push(30);
    printf("%d\n", is_empty());
    printf("%d\n", pop());
    return 0;
}

////////
// STACK
////////

void make_empty(void) {
    first = delete_all(first);
}

bool is_empty(void) {
    return (first == NULL);
}

bool push(int n) {
    struct node *new_node;

    new_node = malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Error: malloc failed in push\n");
        return false;
    }

    new_node->value = n;
    new_node->next = first;
    first = new_node;
    return true;
}

// pop from the top of the stack and return value (not the struct)
int pop(void) {

    if (is_empty()) {
        printf("Stack underflow. Terminating program\n");
        exit(EXIT_FAILURE);
    }
    
    struct node *node_pop = first;
    first = node_pop->next;
    int pop_val = node_pop->value;
    free(node_pop);
    return pop_val;
}

//####################
//## HELPER FUNCTIONS
//####################

struct node *delete_all(struct node *list) {
    struct node *cur = list;
    struct node *nex;

    while(cur != NULL) {
        nex = cur->next;
        free(cur);
        cur = nex;
    }

    return NULL;
}