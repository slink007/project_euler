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
	int count;
};
typedef struct _nl nameList;


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
	names.list = (char **)malloc(2 * sizeof(char *));
	names.count = 0;
	
	for (int i = 0; i < 2; i++)
	{
		read = getdelim(&lineptr, &len, 44, f);  // 44 is a comma
		*((names.list) + i) = (char *)malloc( (read + 1) * sizeof(char));
		names.count += 1;
		strcpy(*((names.list) + i), lineptr);
		
		printf("%s\n", *((names.list) + i) );
	}
	fclose(f);
	
	for (int index = names.count; index >= 0; index--)
	{
		free( *((names.list) + index) );
	}
	free(names.list);
	
	return EXIT_SUCCESS;
	
	/*
	int **p;
	int *q;
	
	p = (int **)malloc(sizeof(int *));  // enough storage to hold a pointer to int
	*p = (int *)malloc(sizeof(int));	// enough storagte to hold an int
	**p = 12;							// storing the int
	
	q = *p;
	
	printf("'q' points where *p points so using '*q' we get: %d\n", *q);
	printf("'**p' dereferencs '*p' so we get: %d\n", **p);
	
	free(*p);
	free(p);
	
	int **x;
	x = (int **)malloc(2 * sizeof(int *));  // should hold 2 pointers
	
	*(x+0) = (int *)malloc(sizeof(int));
	*(x+1) = (int *)malloc(sizeof(int));
	**(x+0) = 1;
	**(x+1) = 2;
	
	printf("%d\n", **x);
	printf("%d\n", **(x+1));
	
	free(x[1]);
	free(x[0]);
	free(x);
	
	return 0;
	*/
}
/*
'q' points where *p points so using '*q' we get: 12
'*p' holds the address of the int so with '*p' we get: -1498598720
'**p' dereferencs '*p' so we get: 12
1
2
*/
