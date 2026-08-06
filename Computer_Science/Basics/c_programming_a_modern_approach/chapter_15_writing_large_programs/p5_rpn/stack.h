#ifndef STACK_H
#define STACK_H
#define STACK_SIZE 100
extern int contents[];
extern int top;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int ch);
int pop(void);
#endif