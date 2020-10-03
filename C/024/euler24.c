/* Project Euler Program 24
 * A permutation is an ordered arrangement of objects. For example, 
 * 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all 
 * of the permutations are listed numerically or alphabetically, we 
 * call it lexicographic order. The lexicographic permutations of 
 * 0, 1 and 2 are:
 * 
 * 			012   021   102   120   201   210
 * 
 * What is the millionth lexicographic permutation of the digits 
 * 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 * 
 * Answer = 2783915460
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void swap(char *s, int a, int b);
int permute(char *str, int len);
void printHelp();


int main(int argc, char *argv[])
{
	bool useDefault = true;  // indicates if default permutations are used
	                         // user did not enter a custom value
	                         
	bool permutationSuccessful = true;  // indicates if desired number
	                                    // of permutations reached
	                                    
	char testString[100];  // holds the pattern - should be more than
	                       // large enough
	                       
	int permutations = 1000000;
	
	// handle command line options
	int option;
	while ( (option = getopt(argc, argv, "hp:n:")) != -1)
	{
		switch (option)
		{
			case 'h':  // prints help text
				printHelp();
				exit (EXIT_SUCCESS);
				break;
			case 'p':  // user enters a different pattern
				strcpy(testString, optarg);
				useDefault = false;
				break;
			case 'n':  // user enters a different number of permutations
				permutations = atoi(optarg);
				if (permutations < 1)
				{
					fprintf(stderr, "Number of permutations must be a "
					"positive integer\n");
					return EXIT_FAILURE;
				}
				break;
			case '?':  // unrecognized options and missing parameters
				perror("That shouldn't happen\n");
				exit (EXIT_FAILURE);
				break;
		}
	}
	
	if (useDefault)
		strcpy(testString, "0123456789");
	int size = strlen(testString);
		
	for (int i = 1; i < permutations; i++)
	{
		int j = permute(testString, size);
		if (j == 0)
		{
			permutationSuccessful = false;
			break;
		}
	}
	
	if (permutationSuccessful)
		printf("\nPermutation %d is %s.\n\n", permutations, testString);
	else
		printf("\nCannot achieve %d permutations.\n\n", permutations);
	
	return EXIT_SUCCESS;
}


void swap(char *s, int a, int b)
{
	char temp=s[a];
	s[a] = s[b];
	s[b] = temp;
}


/* SEPA permutation algorithm comes from 
 * https://quickperm.org/soda_submit.php
 */
int permute(char *str, int len)
{
	int key=len-1;
	int newkey=len-1;

	/* The key value is the first value from the end which
	 * is smaller than the value to its immediate right
	 */
	while( (key > 0) && (str[key] <= str[key-1]) )
		key--;
	key--;

	/* If key < 0 the data is in reverse sorted order,
	 * which is the last permutation.
	 */
	if( key < 0 )
		return 0;

	/* str[key+1] is greater than str[key] because of how key
	 * was found. If no other is greater, str[key+1] is used 
	 */
	newkey=len-1;
	while( (newkey > key) && (str[newkey] <= str[key]) )
		newkey--;

	swap(str, key, newkey);

	/* variables len and key are used to walk through the tail,
	 * exchanging pairs from both ends of the tail.  len and
	 * key are reused to save memory 
	 */
	len--;
	key++;

	/* The tail must end in sorted order to produce the
	 * next permutation. */
	while(len > key)
		swap(str, len--, key++);

	return 1;
}


void printHelp()
{
	printf("\nProject Euler Program 24\n"
           "A permutation is an ordered arrangement of objects. For \n"
           "example, 3124 is one possible permutation of the digits 1, \n"
           "2, 3 and 4. If all of the permutations are listed numerically\n"
           "or alphabetically, we call it lexicographic order. The \n"
           "lexicographic permutations of 0, 1 and 2 are:\n\n"
           "\t012   021   102   120   201   210\n\n"
           "What is the millionth lexicographic permutation of the \n"
           "digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?\n\n"
           "You can optionally pass in a different pattern with the -p\n"
           "option and a different permutation number with the -n \n"
           "option.\n\n");
}
