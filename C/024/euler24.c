#include<stdio.h>
#include<stdlib.h>


void swap(char *s, int a, int b)
{
	char temp=s[a];
	s[a] = s[b];
	s[b] = temp;
}


int permute(char *str, int len)
{
	int key=len-1;
	int newkey=len-1;

	/* The key value is the first value from the end which
	 * is smaller than the value to its immediate right*/
	while( (key > 0) && (str[key] <= str[key-1]) )
		key--;
	key--;

	/* If key < 0 the data is in reverse sorted order, 
	 * which is the last permutation.*/
	if( key < 0 )
		return 0;

	/* str[key+1] is greater than str[key] because of how key 
	 * was found. If no other is greater, str[key+1] is used   */
	newkey=len-1;
	while( (newkey > key) && (str[newkey] <= str[key]) )
		newkey--;


	swap(str, key, newkey);

	/* variables len and key are used to walk through the tail,
	 * exchanging pairs from both ends of the tail.  len and 
	 * key are reused to save memory */
	len--;
	key++;

	/* The tail must end in sorted order to produce the
	 * next permutation. */

	while(len>key)
	{
		swap(str,len,key);
		key++;
		len--;
	}

	return 1;
}


void main()
{
	/* test data */
	char test_string[] = "aabcd";

	/* A short test loop to print each permutation, which are
	 * created in sorted order. */

	do
	{
		printf("%s\n",test_string);
	} while( permute(test_string, strlen(test_string)) );
}
