#include "main.h"

/**
 * print_diagonal - function that draw diagonal line
 * @n: number of times '\' be printed
 */

void print_diagonal(int n)
{
	if (n <= 0)
		_putchar('\n');
	else
	{
		int i, k;

		for (i = 0; i < n; i++)
		{
			for (k = 0; k <= i; k++)
				_putchar(' ');
			_putchar('\\');
			_putchar('\n');
		}
	}
}
