#include <stdio.h>
#include <stdlib.h>

// NODE
struct node {
    int value;              // data
    struct node *next;      // next node
};

// initially, the list is empty
struct node *first = NULL;

void add_to_list(struct node **list, int n);
struct node *read_numbers(void);
struct node *search_list(struct node *list, int n);
void delete_from_list(struct node **list, int n);
struct node *delete_all(struct node *list);
int count_occurrences(struct node *list, int n);
struct node *find_last(struct node *list, int n);
struct node *insert_into_ordered_list(struct node *list, struct node *new_node);

int main(void) {
    
    add_to_list(&first, 40);
    add_to_list(&first, 30);
    add_to_list(&first, 20);
    add_to_list(&first, 10);
    delete_from_list(&first, 10);
    //struct node x = {.value = 35, .next = NULL};
    //first = insert_into_ordered_list(first, &x);
    //printf("%d\n", count_occurrences(first, 30));
    //first = find_last(first, 20);
    //first = delete_from_list(first, 30);
    //first = delete_all(first);
    

    // traverse
    struct node *cur;
    for (cur = first; cur != NULL; cur = cur->next) {
        printf("(node - %d) --> ", cur->value);
    }
    printf("NULL \n");

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
        add_to_list(&first, n);
    }
}


void add_to_list(struct node **list, int n) {
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        new_node = NULL;
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

struct node *insert_into_ordered_list(struct node *list, struct node *new_node) {
    struct node *cur = list, *prev = NULL;

    if (cur == NULL) {
        list = new_node;
        return list;
    }

    while (cur->value <= new_node->value) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        new_node->next = cur;
        list = new_node;
        return list;
    }

    prev->next = new_node;
    new_node->next = cur;
    return list;
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


/*
struct node *delete_from_list(struct node *list, int n) {
    struct node *cur;
	cur = list;

	if (cur->value == n) {
		list = list->next;		// "n" in first node (delete first node)
		free(cur);
		return list;
	}

    while(cur->next != NULL && cur->next->value != n) {
        cur = cur->next;
    }

    if (cur->next != NULL && cur->next->value == n) {
        struct node *del_node = cur->next;
        cur->next = cur->next->next;
        free(del_node);
    }

    return list;
}
*/

void delete_from_list(struct node **list, int n) {

    if (list == NULL || *list == NULL) {
        return;
    }

    struct node *cur = *list;
    
    if (cur->value == n) {
        *list = (*list)->next;
        free(cur);
        return;
    }

    while(cur->next != NULL && cur->next->value != n) {
        cur = cur->next;
    }
    if (cur->next != NULL) {
        struct node *del_node = cur->next;
        cur->next = cur->next->next;
        free(del_node);
    }

}

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

int count_occurrences(struct node *list, int n) {
    int counter = 0;

    while(list != NULL) {
        if (list->value == n) {
            counter++;
        }
        list = list->next;
    }
    return counter;
}

struct node *find_last(struct node *list, int n) {
    struct node *last_so_far;

    while(list != NULL) {
        if (list->value == n) {
            last_so_far = list;
        }
        list = list->next;
    }
    return last_so_far;
}