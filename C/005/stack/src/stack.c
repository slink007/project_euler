#include "stack/stack.h"


void stack(Node **ptr, uint32_t n)
{
	*ptr = (Node *) malloc(sizeof(Node));
	(*ptr)->number = n;
}


bool isEmpty(Node** head)
{
	return *head == NULL;
}


bool isNotEmpty(Node** head)
{
		return *head != NULL;
}


void deleteAtHead(Node** head)
{
	// Stack is empty - nothing to delete
	if (*head == NULL)
		return;
	
	Node* temp = NULL;
	temp = *head;               // temp points where head points
	*head = (*head)->nextNode;  // head now points to the next node
	free(temp);                 // free what head used to point at
}


uint32_t pop(Node** head)
{
	uint32_t n;
	
	n = (*head)->number;
	deleteAtHead(head);
	
	return n;
}


void push(Node** head, uint32_t n)
{
	Node* new = malloc(sizeof(Node));
	new->number = n;
	new->nextNode = *head;
	*head = new;
}
