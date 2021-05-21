#include "list.h"

int main()
{
	List *head;
	
	head = list_create();

	list_add(head, 10);
	list_add(head, 100);
	list_add(head, 1000);

	list_print(head);

	return 0;
}
