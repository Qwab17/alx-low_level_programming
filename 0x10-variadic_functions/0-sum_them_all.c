#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * sum_them_all - function that returns sum of all its paramters.
 * @n: number of paramters passed
 * @...: variable number of paramters
 * Return: sum
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i, sum = 0;

	va_start(ap, n);

	for (i = 0; i < n; i++)
		sum += va_arg(ap, int);

	va_end(ap);
	return (sum);
}
