#ifndef __PROGRAM002_H__
#define __PROGRAM002_H__

#include <stdint.h>


struct _fibonacci {
	uint32_t x;    // number prior to number prior to actual fibonacci number
	uint32_t y;    // number prior to actual fibonacci number
	uint32_t num;  // actual fibonacci number
	uint32_t pos;  // position of number within fibonacci sequence
};
typedef struct _fibonacci fibNum;


// Creates first number in the fibonacci sequence and returns it
fibNum firstFibonacci();

// Increments a fibNum to the next number in fibonacci sequence.
// The fibNum is assumed to be a correct fibonacci number prior to calling
// this function.
void nextFib(fibNum * f);


#endif
