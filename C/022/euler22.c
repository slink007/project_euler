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
	names.list = (char **)malloc(9 * sizeof(char *));
	names.index = -1;
	names.count = 0;
	
	// fill array (works)
	while (names.index < 9)
	{
		read = getdelim(&lineptr, &len, 44, f);  // 44 is a comma
		if (read > 0)  // we got a name
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
			
			// grow the list to allow for another line in the future
			names.list = (char **)realloc(names.list, (names.count + 1) * sizeof(char *));
			
			// debug, verification that we are writing to list correctly
			printf("%s is at index %d\n", *((names.list) + names.index), names.index );
		}
	}
	
	fclose(f);
	free(lineptr);
	
	
	while (names.index >= 0)
	{
		free( *((names.list) + names.index) );
		names.index -= 1;
	}

	free(names.list);
	
	return EXIT_SUCCESS;
}


/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    }
} 
