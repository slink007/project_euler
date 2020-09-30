#include "abund/abundant.h"

/* Research into abundant numbers shows that integers above 20161
 * can be expressed as the sum of 2 abundant numbers.
 */
#define LIMIT 20162
bool listOfAbundantNumbers[LIMIT];


void testNumbersForAbundance()
{
	for (size_t i = 1; i < LIMIT; i++)
		listOfAbundantNumbers[i] = isAbundant(i);
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
	for(size_t i = 1; i <= limit; i++)
	{
		size_t j = n - i;
		if (listOfAbundantNumbers[i] && listOfAbundantNumbers[j])
			return false;
	}
	return true;
}

