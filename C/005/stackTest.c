#include <stdio.h>
#include "stack/stack.h"

int main()
{
	Node* x = NULL;
	uint32_t* result = NULL;
	
	push(&x, 0);
	push(&x, 1);
	
	result = pop(&x);
	printf("\nExpect pop() to return a 1\n");
	if (result == NULL)
		printf("pop() returned a NULL\n");
	else
		printf("pop() returned %u\n", *result);
	
	result = pop(&x);
	printf("Expect pop() to return a 0\n");
	if (result == NULL)
		printf("pop() returned a NULL\n\n");
	else
		printf("pop() returned %u\n", *result);
		
	result = pop(&x);
	printf("Expect pop() to return a NULL\n");
	if (result == NULL)
		printf("pop() returned a NULL\n\n");
	else
		printf("pop() returned %u\n\n", *result);
	
	if (x)
		free(x);
	
	return(EXIT_SUCCESS);
}
