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
#include <unistd.h>
#include "names/names.h"


void printHelp();


int main(int argc, char *argv[])
{
	int option;
	FILE *f = NULL;
	while ( (option = getopt(argc, argv, "hf:")) != -1)
	{
		switch (option)
		{
			case 'f':
				f = fopen(optarg, "r");
				if (f == NULL)
					fprintf(stderr, "Failed to open %s\n", optarg);
				break;
			case 'h':  // prints help text
				printHelp();
				break;
			case '?':  // unrecognized options and missing parameters
				perror("That shouldn't happen\n");
				exit (EXIT_FAILURE);
				break;
		}
	}
	
	// Testing file pointer again in case the program is called without
	// any arguments.
	if (f == NULL)
	{
		fprintf(stderr, "Can not open list of names\n");
		return -1;
	}
	
	
	// create and initialize list to hold names
	nameList names;
	nameList *nl = &names;
	initList(nl);
	fillAndSort(&nl, f);
	fclose(f);
	
	printf("\nThe total score for the names is %zu\n\n", score(nl));
	freeNames(nl);

	return EXIT_SUCCESS;
}


void printHelp()
{
    printf("\nProject Euler Program 22\n\n"
		"Using names.txt, a 46K text file containing over five-thousand first names, \n"
		"begin by sorting it into alphabetical order. Then working out the alphabetical\n"
		"value for each name, multiply this value by its alphabetical position in the \n"
		"list to obtain a name score.\n\n"
		"For example, when the list is sorted into alphabetical order, COLIN, which is\n"
		"worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would\n"
		"obtain a score of 938 × 53 = 49714.\n\n"
		"What is the total of all the name scores in the file?\n\n");

    exit (EXIT_SUCCESS);
}
