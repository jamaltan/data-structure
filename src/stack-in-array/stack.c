#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *
stack_init(int cap)
{
	Stack *s;
	int *data;
	s = malloc(sizeof(Stack)); //记得动态分配内存，不然直接访问的话会报 Segmentation fault
	if(!s){
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	
	/*
	Program received signal SIGSEGV, Segmentation fault.
		0x000000000040057d in stack_init (cap=1024) at stack.c:12
		12              s->cap = cap;
	*/


	s->cap = cap;
	s->len = 0;
	data = malloc(sizeof(int) * cap);
	if(!data){
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	s->data = data;

	return s;
}

void 
stack_push(Stack *s, int val)
{
	if(s->len >= s->cap){
		perror("stack is full");
		exit(EXIT_FAILURE);
	}
	s->data[s->len] = val;
	s->len++;
}

int 
stack_pop(Stack *s)
{
	int element;
	
	if(s->len <= 0){
		perror("stack is empty");
		exit(EXIT_FAILURE);
	}

	s->len--;	
	element = s->data[(s->len)];

	return element;
}

void
stack_print(Stack *s)
{
	int len;
	len = s->len;

	int i;

	for(i = 0; i < len; i++){
		printf("idx: %d, val: %d\n", i, s->data[i]);
	}
}
