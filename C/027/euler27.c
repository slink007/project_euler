/* Project Euler Program 27
 * Euler discovered the remarkable quadratic formula:
 *                       n² + n + 41
 * which will produce 40 primes for the consecutive values
 * n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 
 * is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is 
 * clearly divisible by 41.
 * 
 * The incredible formula  n² − 79n + 1601 was discovered, which 
 * produces 80 primes for the consecutive values n = 0 to 79. The 
 * product of the coefficients, −79 and 1601, is −126479.
 * 
 * Considering quadratics of the form:
 *     n² + an + b, where |a| < 1000 and |b| <= 1000
 * where |n| is the modulus/absolute value of n
 * find the product of the coefficients, a and b, for the quadratic 
 * expression that produces the maximum number of primes for consecutive
 * values of n, starting with n = 0.
 */
 
 
/* Per the problem statement the formula must produce a prime when n
 * is 0.  If we solve 0² + a(0) + b we get b and therefore b must be 
 * prime.
 * 
 * Now we solve for n = 1.  1² + a(1) + b == 1 + a + b.  We know that
 * b is prime, and all primes except for 2 are odd, and since an odd 
 * plus an odd yields an even then "a + 1" has to be even in order to
 * produce a prime when it is added onto an odd b.  This means that a 
 * has to be odd.
 */
 
 
