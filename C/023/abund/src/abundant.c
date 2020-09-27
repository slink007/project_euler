#include "abund/abundant.h"


/* 5000 is semi-arbitrary.  I did one iteration with a much larger
 * number and then read the resulting abundantCounter.  It was nearly
 * 5000 so I just used 5000 as it is a nice, round number and big 
 * enough to ensure a correct answer.
 */
size_t listOfAbundantNumbers[5000];  // the name says it all...
int abundantCounter = 0;             // how many numbers written to list


void addNumber(size_t n)
{
	listOfAbundantNumbers[abundantCounter] = n;
	abundantCounter++;
}


size_t sumOfDivisors(size_t n)
{
	size_t sum = 1; // Everything is divisble by 1 so sum will always
					// be at least this large.
	size_t limit = (size_t) sqrt(n);

	
	for (size_t i = 2; i <= limit; i++)
	{
		if (n % i == 0)
		{
			sum += i;
			
			size_t otherFactor = n / i;
			if (otherFactor != i)
				sum += otherFactor;
		}
	}
	
	return sum;
}


bool isAbundant(size_t n)
{
	return sumOfDivisors(n) > n;
}


bool notAbundantSum(size_t n)
{
	size_t limit = n / 2;
	for (int i = 0; i < abundantCounter; i++)
	{
		if (listOfAbundantNumbers[i] > limit)
			break;

		if ( isAbundant(n - listOfAbundantNumbers[i]) )
			return false;
	}
	return true;
}

