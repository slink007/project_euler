#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>


struct node_t
{
	uint32_t number;
	struct node_t * nextNode;
};
typedef struct node_t Node;


// Pass in the address of the stack pointer and this returns True if 
//stack is empty.
bool isEmpty(Node** head);


// Pass in the address of the stack pointer and this returns True if 
//stack is not empty.
bool isNotEmpty(Node** head);


// Pass in the address of a Node pointer, along with a value to store,
// and this adds a new node to the stack.  The head of the stack is moved
// to point at this new node.
void push(Node** head, uint32_t n);


// Pass in the address of a Node pointer and this pops the node off 
// the top of the stack and returns the stored value.  No protection 
// for empty stack so check it before you pop!
uint32_t pop(Node**);


#endif
