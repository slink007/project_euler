#ifndef __NAMES_H__
#define __NAMES_H__


#include <stdlib.h>
#include <string.h>


struct _nl
{
	char **list;	// An array of character pointers (strings)
	int index;		// Controls where in the list a name is written
	int count;		// Count of how many names are in the list
};
typedef struct _nl nameList;


// Allocates memory for the names list and initializes the index and
// count values.
void initList(nameList *nl);


// Frees memory for each name in the list and for the list itself.
void freeNames(nameList *nl);


// Use insertion sort to sort the names in the list.
void sortNames(nameList *nl);


// Returns the total of all name scores
size_t score(nameList *nl);

#endif
