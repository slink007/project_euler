#ifndef __LIST_H__
#define __LIST_H__

#include <stdint.h>


struct node_t
{
	uint32_t number;
	struct node_t * nextNode;
};
typedef struct node_t Node;
//typedef Node* NodePtr;


#endif
