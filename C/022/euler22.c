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
	
	for (int i = 0; i < 10; i++)
	{
		read = getdelim(&lineptr, &len, 44, f);  // 44 is a comma
		size_t len = strlen(lineptr);
		lineptr[len - 1] = '\0';  // remove the comma
		lineptr[len - 2] = '\0';  // remove trailing quote mark
		memmove(lineptr, lineptr+1, strlen(lineptr));  // remove first quote mark
		printf("%s\n", lineptr);
	}
	
	free(lineptr);
	fclose(f);
	return 0;
}