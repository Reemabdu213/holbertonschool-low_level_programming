#include "main.h"

/**
 * prime_helper - checks recursively if n has a divisor starting from i
 * @n: number to check
 * @i: current divisor to test
 *
 * Return: 1 if n is prime, 0 otherwise
 */
static int prime_helper(int n, int i)
{
	if (i * i > n)
	{
		return (1);
	}
	if (n % i == 0)
	{
		return (0);
	}
	return (prime_helper(n, i + 1));
}

/**
 * is_prime_number - returns 1 if the input integer is a prime number
 * @n: integer to evaluate
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	if (n == 2)
	{
		return (1);
	}
	return (prime_helper(n, 2));
}
