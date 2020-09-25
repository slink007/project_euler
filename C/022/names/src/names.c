#include "names/names.h"


void initList(nameList *nl)
{
	nl->list = (char **)malloc(sizeof(char *));
	nl->index = -1;
	nl->count = 0;
}


void freeNames(nameList *nl)
{
	// Free each name in the list
	while (nl->index >= 0)
	{
		free( *((nl->list) + nl->index) );
		nl->index -= 1;
	}
	
	// Free the list itself
	free(nl->list);
}


void sortNames(nameList *nl)
{
	for (int i = 1; i < (nl->count); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			/* If the name below the current name is larger than the current name
			 * do an insertion swap.  If not then no need to keep trying.
			 */
			if ( strcmp( *((nl->list) + j), *((nl->list) + j + 1) ) > 0 )
			{
				char *temp = *((nl->list) + j);
				*((nl->list) + j) = *((nl->list) + j + 1);
				*((nl->list) + j + 1) = temp;
			}
			else
				break;
		}
	}
}


// A helper function for score().  It returns 0 for quotes and commas
// so there is no need to filter them out of the original names.  For
// capital letters it returns 1 for 'A", 2 for 'B', ... , 26 for 'Z'.
size_t charScore(char c)
{
	switch (c)
	{
		case '"':
		case ',':
			return 0;
			break;
		default:
			// Correct values for 'A' to 'Z' but will break on other values.
			return (size_t)( (c - 'A') + 1);
			break;
	}
}



size_t score(nameList *nl)
{
	size_t total = 0;
	while ( (nl->index) >= 0)
	{
		size_t subtotal = 0;
		int length = (int)strlen(*((nl->list) + nl->index));
		
		// add up scores for each character in the name
		for (int i = 0; i < length; i++)
			subtotal += charScore( *(*((nl->list) + nl->index) + i) );
		
		// adjust for position within the list
		subtotal *= (nl->index) + 1;
		nl->index -= 1;
		total += subtotal;
	}
	
	return total;
}
