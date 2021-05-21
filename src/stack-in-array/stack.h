#ifndef __STACK_H__
#define __STACK_H__

#define int int
#define MAX_ELEMENT 1024

typedef struct stack {
	int len;
	int cap;
	int *data;
} Stack;

Stack* stack_init();
void stack_push(Stack *s, int val);
int stack_pop(Stack *s);
void stack_print(Stack *s);

#endif /* __STACK_H__ */
