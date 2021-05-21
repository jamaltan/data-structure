#include "stack.h"

int main()
{
	int cap = 4;
	Stack *s;
	
	s = stack_init(cap);
	int i;

	for( i = 1; i <= cap; i++ ){
		stack_push(s, i+11);
	}

	stack_print(s);

	printf("stack pop val: %d\n", stack_pop(s));
	printf("stack pop val: %d\n", stack_pop(s));
	printf("stack pop val: %d\n", stack_pop(s));
	printf("stack pop val: %d\n", stack_pop(s));
	printf("stack pop val: %d\n", stack_pop(s));

	return 0;
}
