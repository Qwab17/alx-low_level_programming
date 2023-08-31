#include "main.h"

/**
 * prime_a - function that prints if integer is a prime number
 * @a: input
 * @b: divisor
 * Return: (0)
 */

int prime_a(int a, int b)
{
	if (a <= 1 || (a != b && a % b == 0))
	{
		return (0);
	}
	else if (a == b)
	{
		return (1);
	}
	return (prime_a(a, b + 1));
}

/**
 * is_prime_number - function that returns 1 if integer is a prime
 * @n: the input number
 * Return: 0 or 1
 */

int is_prime_number(int n)
{
	return (prime_a(n, 2));
}
