/* Project Euler 19
 * You are given the following information, but you may prefer to do some research for yourself.
 *
 *   1 Jan 1900 was a Monday.
 *   Thirty days has September,
 *   April, June and November.
 *   All the rest have thirty-one,
 *   Saving February alone,
 *   Which has twenty-eight, rain or shine.
 *   And on leap years, twenty-nine.
 *   A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 *
 * Answer = 171
 */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define DAYSINWEEK 7
#define STARTYEAR 1901
#define ENDYEAR 2000

typedef enum
{
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
} Month;


unsigned int daysInMonth(unsigned int year, Month month);
void printError(char* name);
void printHelp();


int main(int argc, char *argv[])
{
	unsigned int daysSoFar = 2;  // 2 because 1-1-1901 is a Tuesday (2nd day of the week)
	unsigned int sundayCount = 0;
	
	// process options from command line
	int option;
	while ( (option = getopt(argc, argv, "h")) != -1)
	{
		switch (option)
		{
			case 'h':  // prints help text
				printHelp();
				break;
			case '?':  // unrecognized options and missing parameters
				printError(argv[0]);
				break;
		}
	}
	
	for (unsigned int year = STARTYEAR; year <= ENDYEAR; year++)
	{
		for (Month m = January; m <= December; m++)
		{
			daysSoFar += daysInMonth(year, m);
			if (daysSoFar % DAYSINWEEK == 0)
				sundayCount++;
		}
	}
	
	printf("\nThere were %u months beginning on a Sunday between %d and %d inclusive.\n\n",
		sundayCount, STARTYEAR, ENDYEAR);
	
	return EXIT_SUCCESS;
}


unsigned int daysInMonth(unsigned int year, Month month)
{
	switch (month)
	{
		case April:
		case June:
		case September:
		case November:
			return 30;
			break;
		case February:
			if ( year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) )  // leap year
				return 29;
			return 28;
			break;
		case January:
		case March:
		case May:
		case July:
		case August:
		case October:
		case December:
		default:
			return 31;
			break;
	}
}

void printError(char* name)
{
	fprintf (stderr,"\nUsage: %s\n", name);
	fprintf (stderr,"Usage: %s -h \n", name);
	exit (EXIT_FAILURE);
}


void printHelp()
{
    printf("\nProject Euler Program 19\n\n"
        "How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?\n\n");

    exit (EXIT_SUCCESS);
}
