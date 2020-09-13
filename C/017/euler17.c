/* Project Euler Program 17
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.  If all the 
 * numbers from 1 to 1000 (one thousand) inclusive were written out in words, 
 * how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 * letters. The use of "and" when writing out numbers is in compliance with
 * British usage and must be used to get the correct answer for this problem.
 * 
 * Answer = 21124
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "letterCount/count.h"

#define LIMIT 1000

void printError(char* name);
void printHelp();


int main(int argc, char *argv[])
{
	unsigned int limit = LIMIT;
	int temp;
	
	// process options from command line
	int option;
	while ( (option = getopt(argc, argv, "l:h")) != -1)
	{
		switch (option)
		{
			case 'l':  // choose a new limit for when to stop writing numbers
				temp = atoi(optarg);
				if ( (temp < 1) || (temp > 9999) )
					printError(argv[0]);
				else
					limit = (unsigned int)temp;
				break;
			case 'h':  // prints help text
				printHelp();
				break;
			case '?':  // unrecognized options and missing parameters
				printError(argv[0]);
				break;
		}
	}
	
	
	// Get the sum of all of the letters
	unsigned int sum = 0;
	for (unsigned int i = 1; i <= limit; i++)
		sum += letterCount(i);
	printf("\nThe number of letters used when writing 1 to %u as words is %u\n\n", 
         limit, sum);
	
	return EXIT_SUCCESS;
}


void printError(char* name)
{
	fprintf (stderr,"\nUsage: %s\n", name);
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s -l <limit>\n", name);
	fprintf (stderr,"<limit> is a positive integer greater than 1 and less than 10,000\n\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
    printf("\nProject Euler Program 17\n\n"
        "If the numbers 1 to 5 are written out in words: one, two, three, four, five,\n"
		"then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.  If all the \n"
		"numbers from 1 to 1000 (one thousand) inclusive were written out in words, how\n"
		"how many letters would be used?\n\n"
        "You can solve this problem as-is or optionally enter a different limit (1 -> N)\n"
        "Use -l <limit> to change the limit.\n\n");

    exit (EXIT_SUCCESS);
}
