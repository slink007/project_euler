/* Project Euler Program 11
 * In the 20×20 grid below the four numbers with the largest product are
 *   26 [@ (G, AI)]
 *   63 [@ (H, AJ)]
 *   78 [@ (I, AK)]
 *   14 [@ (J, AL)]
 *
 *   | AA|AB|AC|AD|AE|AF|AG|AH|AI|AJ|AK|AL|AM|AN|AO|AP|AQ|AR|AS|AT
 *   |___|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__ 
 * A | 08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
 * B | 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
 * C | 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
 * D | 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
 * E | 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
 * F | 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
 * G | 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
 * H | 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
 * I | 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
 * J | 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
 * K | 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
 * L | 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
 * M | 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
 * N | 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
 * O | 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
 * P | 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
 * Q | 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
 * R | 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
 * S | 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
 * T | 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
 *
 * The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 *
 * What is the greatest product of thirteen adjacent numbers in the same
 * direction (up, down, left, right, or diagonally) in the 20×20 grid?
 *
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "arrays/arrays.h"

void printError(char* name);
void printHelp();


int main(int argc, char ** argv)
{
	/*uint8_t bigGrid[20][20] = {
		{8,2,22,97,38,15,0,40,0,75,4,5,7,78,52,12,50,77,91,8},
		{49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,4,56,62,0},
		{81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,3,49,13,36,65},
		{52,70,95,23,4,60,11,42,69,24,68,56,1,32,56,71,37,2,36,91},
		{22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
		{24,47,32,60,99,3,45,2,44,75,33,53,78,36,84,20,35,17,12,50},
		{32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
		{67,26,20,68,2,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21},
		{24,55,58,5,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
		{21,36,23,9,75,0,76,44,20,45,35,14,0,61,33,97,34,31,33,95},
		{78,17,53,28,22,75,31,67,15,94,3,80,4,62,16,14,9,53,56,92},
		{16,39,5,42,96,35,31,47,55,58,88,24,0,17,54,24,36,29,85,57},
		{86,56,0,48,35,71,89,7,5,44,44,37,44,60,21,58,51,54,17,58},
		{19,80,81,68,5,94,47,69,28,73,92,13,86,52,17,77,4,89,55,40},
		{4,52,8,83,97,35,99,16,7,97,57,32,16,26,26,79,33,27,98,66},
		{88,36,68,87,57,62,20,72,3,46,33,67,46,55,12,32,63,93,53,69},
		{4,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36},
		{20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,4,36,16},
		{20,73,35,29,78,31,90,1,74,31,49,71,48,86,81,16,23,57,5,54},
		{1,70,54,71,83,51,54,69,16,92,33,48,61,43,52,1,89,19,67,48}
	};*/
	
	size_t quantity = 13;
	
	if (argc == 1)
		printError(argv[0]);
	else if (argc == 2)
	{
		if (strcmp("-h", argv[1]) == 0 )
			printHelp();
		//else
			//printError(argv[0]);
	}
	
	//printf("Biggest product of %zu consecutive numbers is %zu\n", 
	//	quantity, adjacentProduct(bigGrid, 20, quantity));
	//Point p;
	//p.x = 2;
	//p.y = 2;
	//printf("\n%zu\n", prodUp(20, bigGrid, p, 3));
	

	Matrix2D foo;
	Matrix2D *fooPtr = &foo;
	/*foo.rows = 20;
	foo.cols = 20;
	foo.values = malloc(foo.rows * foo.cols * sizeof(int));*/
	matrixInit(&fooPtr, 20, 20);
		

	// Try to open file to fill our matrix
	FILE *f = fopen(argv[1], "r");
	
	fillData(fooPtr, f);
	
	/*if (f == NULL)
	{
		fprintf(stderr, "Unable to open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	// Read file into memory
	char *buffer = NULL;
	size_t bufsize = 400;
	size_t charsRead;
	buffer = (char *)malloc(bufsize * sizeof(char));
	charsRead = getline(&buffer, &bufsize, f);
	printf("Read %zu characters from the file\n", charsRead);
*/
	// Parse through memory looking for the data
	//char *token = NULL;
	//size_t i = 0;
	//token = strtok(buffer, ",");
	//while (token != NULL)
	//{
//		foo.values[i] = atoi(token);  // save data to matrix
//		i++;
//		token = strtok(NULL, ",");
//	}
	
	// Print matrix to prove that it's getting filled
	/*unsigned int count = 1;
	for (unsigned int j = 0; j < 400; j++)
	{
		if (count < 20)
			printf("%2d, ", foo.values[j]);
		else
		{
			printf("%2d\n", foo.values[j]);
			count = 0;
		}
		count++;
	}*/
	printMatrix(fooPtr);

	fclose(f);
	//free(buffer);
	free(foo.values);
	
	return EXIT_SUCCESS;

}


void printError(char* name)
{
	fprintf (stderr,"Usage: %s \n", name);
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s <number>\n", name);
	fprintf (stderr,"<number> must be a positive, whole number.\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
	printf("\nProject Euler Program 11\n\n"
		"In the 20×20 grid below the four adjacent numbers with the largest product are "
		"26, 63, 78, and 14.  The product of those numbers is 1788696.\n\n"
		"  | AA|AB|AC|AD|AE|AF|AG|AH|AI|AJ|AK|AL|AM|AN|AO|AP|AQ|AR|AS|AT\n"
		"  |___|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__\n"
		"A | 08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08\n"
		"B | 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\n"
		"C | 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\n"
		"D | 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\n"
		"E | 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\n"
		"F | 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\n"
		"G | 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70\n"
		"H | 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21\n"
		"I | 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72\n"
		"J | 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95\n"
		"K | 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\n"
		"L | 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\n"
		"M | 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\n"
		"N | 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\n"
		"O | 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\n"
		"P | 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\n"
		"Q | 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\n"
		"R | 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\n"
		"S | 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\n"
		"T | 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48\n\n"
		"What would be the greatest product of 13 adjacent numbers?\n\n");

	exit (EXIT_SUCCESS);
}
