/* Project Euler Program 22
 * Using names.txt, a 46K text file containing over five-thousand first names, 
 * begin by sorting it into alphabetical order. Then working out the 
 * alphabetical value for each name, multiply this value by its alphabetical 
 * position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which 
 * is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
 * would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 *
 * Answer = 871198282
 */

/* An examination of the file shows that all letters in all names have the same
 * case (UPPER) and that the names are comma separated.  Also, there are no line
 * feeds or new lines until the end of the file so we can't read out a line at a
 * time with getline.  
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


struct _nl
{
	char **list;
	int index;
	int count;
};
typedef struct _nl nameList;

void sortNames(nameList *nl);
void freeNames(nameList *nl);
size_t charScore(char c);
size_t score(nameList *nl);

int main(int argc, char *argv[])
{
	int option;
	FILE *f = NULL;
	while ( (option = getopt(argc, argv, "f:")) != -1)
	{
		switch (option)
		{
			case 'f':
				f = fopen(optarg, "r");
				if (f == NULL)
					fprintf(stderr, "Failed to open %s\n", optarg);
				break;
			case '?':  // unrecognized options and missing parameters
				perror("That shouldn't happen\n");
				exit (EXIT_FAILURE);
				break;
		}
	}
	
	// Get names from the file
	if (f == NULL)
	{
		fprintf(stderr, "Can not open list of names\n");
		return -1;
	}
	char *lineptr = NULL;
	size_t len, read;
	nameList names;
	names.list = (char **)malloc(sizeof(char *));
	names.index = -1;
	names.count = 0;
	
	// fill and sort array
	/* TODO
	 * Using getdelim only works if I modify the supplied file and add a final comma onto 
	 * the end of it.  Rework this section to use getc so that ALL the characters can be
	 * read and used without modifying the file.
	 */
	while ( (read = getdelim(&lineptr, &len, 44, f)) != EOF)  // 44 is a comma
	{
		// make index correct for where in the list to make storage for
		// the new name
		names.index += 1;
		
		// count the new name
		names.count += 1;
		
		// add storage for the new name to the list
		// +1 is for terminating '\0'
		*((names.list) + names.index) = malloc( (read + 1) * sizeof(char));
		
		// copy the name we read into the storage
		strcpy(*((names.list) + names.index), lineptr);
		
		// sort the list as names are added
		sortNames(&names);
		
		// grow the list to allow for another line in the future
		names.list = (char **)realloc(names.list, (names.count + 1) * sizeof(char *));
	}
	
	/*for (int i = 0; i < names.count; i++)
		printf("%s\n", *((names.list) + i));
	*/
	
	// test score
	printf("\n%zu\n", score(&names));
	
	fclose(f);
	free(lineptr);
	freeNames(&names);

	return EXIT_SUCCESS;
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


void freeNames(nameList *nl)
{
	while (nl->index >= 0)
	{
		free( *((nl->list) + nl->index) );
		nl->index -= 1;
	}
	free(nl->list);
}


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
	//int foo = 0;
	while ( (nl->index) > 0)
	{
		size_t subtotal = 0;
		int length = (int)strlen(*((nl->list) + nl->index));
		for (int i = 0; i < length; i++)
			subtotal += charScore( *(*((nl->list) + nl->index) + i) );
		printf("%s ==> %zu * %d = ", *((nl->list) + nl->index), subtotal, (nl->index));
		subtotal *= (nl->index);
		printf("%zu\n", subtotal);
		nl->index -= 1;
		//foo += 1;
		total += subtotal;
	}
	
	return total;
}
