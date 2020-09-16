/* Project Euler Program 21
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n 
 * which divide evenly into n).  If d(a) = b and d(b) = a, where a ≠ b, then a 
 * and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 *
 * Answer = 31626
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void printError(char* name);
void printHelp();
unsigned int sumOfDivisors(unsigned int n);

int main(int argc, char *argv[])
{
	unsigned int sumOfAmicable = 0;
	
	for (int x = 1; x < 10; x++)
		printf("Sum of divisors for %d is %u\n", x, sumOfDivisors( (unsigned int)x ));
	printf("Sum of divisors for 220 is %u\n", sumOfDivisors(220));
	printf("Sum of divisors for 284 is %u\n", sumOfDivisors(284));
	
	return EXIT_SUCCESS;
}


unsigned int sumOfDivisors(unsigned int n)
{
	unsigned int sum = 1;   // Everything is divisble by 1 so sum will always
							// be at least this large.
	unsigned int limit = n / 2;
	
	for (unsigned int i = 2; i <= limit; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	
	return sum;
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
