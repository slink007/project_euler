#include <stdio.h>
#include "stack/stack.h"

int main()
{
	// Test creating a new stack directly
	Node n;
	n.number = 7;
	n.nextNode = NULL;
	printf("\nExpect to find that node contains a 7\n");
	printf("This node contains a %u\n\n", n.number);

	// Test creating a new stack with a pointer
	Node* m = NULL;
	printf("Expect to find that the stack is empty\n");
	if (isEmpty(&m))
		printf("Before assigning a value the stack is empty\n");
	
	m = (Node *) malloc(sizeof(Node));
	printf("Expect to find that the stack is no longer empty\n");
	if (isEmpty(&m))
		printf("This should not print.\n\n");
	else
		printf("The stack is not empty now\n\n");
		
	if (m)
	{
		m->number = 42;
		m->nextNode = NULL;
		printf("Expect to find that node contains a 42\n");
		printf("This node contains a %u\n\n", m->number);
		free(m);
	}

	// Test creating a stack with the stack() function
	Node* x = NULL;
	stack(&x, 187);
	if (x)
	{
		printf("Expect to find that node contains a 187\n");
		printf("This node contains a %u\n", x->number);
		
		// Test that a new value can be pushed onto the stack
		insertAtHead(&x, 255);
		printf("Expect to find that node contains a 255\n");
		printf("Added new node, the head now contains %u\n", x->number);
		
		// Test the ability to remove items from the stack
		uint32_t count = 0;
		while (x != NULL)
		{
			deleteAtHead(&x);
			count += 1;
		}
		printf("Expect to delete 2 nodes\n");
		printf("Deleted %u nodes\n\n", count);
	}
	else
	{
		fprintf(stderr, "Failed to allocate new stack\n");
		exit(EXIT_FAILURE);
	}

	return(EXIT_SUCCESS);
}
