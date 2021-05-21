#ifndef __LIST_H
#define __LIST_H

#include <stdbool.h>

typedef struct elt {
	struct elt *next;
	int val;
} Elt;

typedef struct elt List;

List* list_create();
bool list_add(List *head, int val);
bool list_del(List *head, int val);
bool list_search(List *head, int val);
void list_print(List *head);

#endif /* __LIST_H */
