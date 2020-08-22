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


// Pass in the address of a Node pointer, along with a value to store,
// and a new stack is created.  The pointer now points at the head of 
// that stack.
void stack(Node** ptr, uint32_t n);


// Return True if stack is empty.
bool isEmpty(Node** head);


// Pass in the address of the stack pointer and this deletes node at 
// the head of the stack.
void deleteAtHead(Node** head);


// Pass in the address of a Node pointer, along with a value to store,
// and this adds a new node to the stack.  The head of the stack is moved
// to point at this new node.
void push(Node** head, uint32_t n);


// Pops a node off of the stack and returns the stored value.
uint32_t* pop(Node**);


#endif
