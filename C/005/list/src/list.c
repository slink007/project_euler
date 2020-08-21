#include "list/list.h"


void list(Node **ptr, uint32_t n)
{
	*ptr = (Node *) malloc(sizeof(Node));
	(*ptr)->number = n;
}


bool isEmpty(Node** head)
{
	return *head == NULL;
}


void deleteAtHead(Node** head)
{
	// List is empty - nothing to delete
	if (head == NULL)
		return;
	
	Node* temp = NULL;
	temp = *head;               // temp points where head points
	*head = (*head)->nextNode;  // head now points to the next node
	free(temp);                 // free what head used to point at
}


void insertAtHead(Node** head, uint32_t n)
{
	Node* new = malloc(sizeof(Node));
	new->number = n;
	new->nextNode = *head;
	*head = new;
}
