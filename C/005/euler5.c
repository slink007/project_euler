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
#include "primes/primes.h"


int main()
{
	// Test list functionality
	Node n;
	n.number = 7;
	n.nextNode = NULL;
	printf("This node contains a %u\n", n.number);

	Node* m = NULL;
	
	if (isEmpty(&m))
		printf("Before assigning a value the list is empty\n");
	
	m = (Node *) malloc(sizeof(Node));
	
	if (isEmpty(&m))
		printf("This should not print.\n");	
	
	if (m)
	{
		m->number = 42;
		m->nextNode = NULL;
		printf("This node contains a %u\n", m->number);
		free(m);
	}

	Node* x = NULL;
	list(&x, 187);
	if (x)
	{
		printf("This node contains a %u\n", x->number);
		insertAtHead(&x, 255);
		printf("Added new node, the head now contains %u\n", x->number);
		uint32_t count = 0;
		while (x != NULL)
		{
			deleteAtHead(&x);
			count += 1;
		}
		printf("Deleted %u nodes\n\n", count);
	}
	else
	{
		printf("Zut allors!  Zee memory, she was not allocated!\n");
	}

	// Test primes
	if (isPrime(2))
		printf("This should print because 2 is prime\n");
	if (isPrime(3))
		printf("This should print because 3 is prime\n");
	if (isPrime(4))
		printf("This should not print because 4 is not prime\n\n");

	return(EXIT_SUCCESS);
}
