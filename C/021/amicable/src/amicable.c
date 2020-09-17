#include "amicable/amicable.h"

unsigned int sumOfDivisors(unsigned int n)
{
	unsigned int sum = 1;   // Everything is divisble by 1 so sum will always
							// be at least this large.
							
	unsigned int limit = n / 2;  // Largest divisor results from n / 2
								 // so no need to check beyond this.
	
	for (unsigned int i = 2; i <= limit; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	
	return sum;
}
