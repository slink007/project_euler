#include <stdio.h>
#include "stack/stack.h"

int main()
{
	Node* x = NULL;
	uint32_t result = 0;
	
	push(&x, 0);
	push(&x, 1);
	
	result = pop(&x);
	printf("\nExpect pop() to return a 1\n");
	printf("pop() returned %u\n", result);
	
	result = pop(&x);
	printf("\nExpect pop() to return a 0\n");
	printf("pop() returned %u\n\n", result);
	
	if (isEmpty(&x))
		free(x);
	else
	{
		printf("Why is the stack not empty?\n\n");
		return(EXIT_FAILURE);
	}
	
	return(EXIT_SUCCESS);
}
