#ifndef __LIST_H__
#define __LIST_H__

#include <stdint>


struct Node
{
	uint32_t data;
	struct node_t * nextNode;
};
typedef Node* NodePtr;


#endif;
