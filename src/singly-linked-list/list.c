#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List *
list_create()
{
	List *head;
	// 头节点一般存放数据吗？

	head = malloc(sizeof(List));
	head->next = NULL;
	head->val = 0;  //如果头节点不存放值， 那么是不是头节点就和其他正常节点不一致，列外区分。还是头节点只是一个普通的数据节点， 那么头节点是否应该存放数据， 数据初始化的值是啥？
	return head;
}


bool
list_add(List *head, int val)
{
	Elt *elt;
	Elt *cur;

	elt = malloc(sizeof(Elt));
	elt->val = val;
	elt->next = NULL;

	for( cur = head->next ; cur ; cur = cur->next ){
		printf("cur addr: %p\n", cur);
	}

	cur->next = elt;
	
	return true;
}


bool
list_del(List *head, int val)
{
	return true;	
}

bool
list_search(List *head, int val)
{
	return true;
}


void
list_print(List *head)
{
	Elt *cur;

	for ( cur = head->next; cur; cur = cur->next ) {
		printf("cur val: %d\n", cur->val);
	}
}
