/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *
 * This is asking for the Least Common Multiple (LCM) of the listed numbers.  The process is:
 *     1. Find all prime numbers in that list and multiply them together.
 *     2. Break all the non-prime nummers down into prime products.  '9' becomes 3 * 3 or 3^2,
 *        '10' becomes 2 * 5, and so on.
 *     3. Determine how many times a prime number appears in the numbers from (2) and use that
 *        frequency to multiply the prime number by the product from (1).  For example, if
 *        the highest occurance of 2 was 3, achieved by 8 = 2 * 2 * 2, then we would multiply
 *        the product from (1) by 2 * 2 * 2.
 *
 * Answer = 232792560
 */

#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"

int main()
{
	Node n;
	n.number = 7;
	n.nextNode = NULL;
	printf("This nodes contains a %u\n", n.number);

	Node* m = NULL;
	m = malloc(sizeof(Node));
	if (m)
	{
		m->number = 42;
		m->nextNode = NULL;
		printf("This nodes contains a %u\n", m->number);
		free(m);
	}

	return(EXIT_SUCCESS);
}
