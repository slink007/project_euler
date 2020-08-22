#include <stdio.h>
#include "stack/stack.h"

nt main()
{
	// Test creating
	Node n;
	n.number = 7;
	n.nextNode = NULL;
	printf("This node contains a %u\n", n.number);

	Node* m = NULL;
	
	if (isEmpty(&m))
		printf("Before assigning a value the stack is empty\n");
	
	m = (Node *) malloc(sizeof(Node));
	
	if (isEmpty(&m))
		printf("This should not print.\n");	
	
	if (m)
	{
		m->number = 42;
		m->nextNode = NULL;
		printf("This node contains a %u\n", m->number);
		free(m);
	}

	Node* x = NULL;
	stack(&x, 187);
	if (x)
	{
		printf("This node contains a %u\n", x->number);
		insertAtHead(&x, 255);
		printf("Added new node, the head now contains %u\n", x->number);
		uint32_t count = 0;
		while (x != NULL)
		{
			deleteAtHead(&x);
			count += 1;
		}
		printf("Deleted %u nodes\n\n", count);
	}
	else
	{
		printf("Zut allors!  Zee memory, she was not allocated!\n");
	}

	return(EXIT_SUCCESS);
}
