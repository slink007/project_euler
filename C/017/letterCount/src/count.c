#include "letterCount/count.h"


unsigned ones(unsigned n)
{
	// 3 @ index 1 since 'one' has 3 letters
	// 3 @ index 2 since 'two' has 3 letters, etc.
	const static unsigned ones[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
	return ones[n];
}


unsigned teens(unsigned n)
{
	// 3 @ index 0 since 'ten' has 3 letters
	// 6 @ index 1 since 'eleven' has 6 letters, etc.
	const static unsigned int teens[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	return teens[n - 10];
}


unsigned tens(unsigned n)
{
	// 6 @ index 2 since 'twenty' has 6 letters
	// 6 @ index 3 since 'thirty' has 6 letters, etc.
	const static unsigned int  tens[] = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};
	unsigned int sum = tens[n / 10];
	sum += letterCount(n % 10);
	return sum;
}


unsigned hundreds(unsigned n)
{
	unsigned int sum = letterCount(n / 100);
	unsigned int tensAndOnes = n % 100;
	sum += 7;  // 'hundred' has 7 letters
	if (tensAndOnes)
	{
		sum += 3;  // 'and' has 3 letters
		sum += letterCount(tensAndOnes);
	}
	return sum;
}


unsigned int thousands(unsigned n)
{
	unsigned int sum = letterCount(n / 1000);
	unsigned int hundreds = n % 1000;
	sum += 8;  // 'thousand' has 8 letters
	sum += letterCount(hundreds);
	return sum;
}


unsigned int letterCount(unsigned int n)
{
	/* Takes a positive integer and returns the number of letters needed to
	 * express that number in words.  Does not count spaces or hyphens. For example,
	 * 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred 
	 * and fifteen) contains 20 letters. The use of "and" when writing out numbers 
	 * is in compliance with British usage.
	 *
	 * Input n assumed to be less than 10,000.
	 */
	unsigned int sum = 0;

	if (n < 10)
		sum += ones(n);			// 1 to 9
	else if (n < 20)
		sum += teens(n);		// 10 to 19
	else if (n < 100)
		sum += tens(n);			// 20 to 99
	else if (n < 1000)		
		sum += hundreds(n);		// 100 to 999
	else
		sum += thousands(n);	// 1000 to 9999

	return sum;
}
