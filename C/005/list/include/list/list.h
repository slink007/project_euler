#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>


struct node_t
{
	uint32_t number;
	struct node_t * nextNode;
};
typedef struct node_t Node;
//typedef Node* NodePtr;


// Pass in the address of a Node pointer, along with a value to store,
// and a new list is created.  The pointer now points at the head of 
// that list.
void list(Node **ptr, uint32_t n);


// Return True if list is empty or False if it is not empty.
bool isEmpty(Node* head);


#endif
