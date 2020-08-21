#include "list/list.h"


void list(Node **ptr, uint32_t n)
{
	*ptr = (Node *) malloc(sizeof(Node));
	(*ptr)->number = n;
}


bool isEmpty(Node* head)
{
	return head == NULL;
}
