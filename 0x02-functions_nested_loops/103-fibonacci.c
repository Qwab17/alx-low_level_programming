#include <stdio.h>

/**
 *  main - print sum of even value
 *  Return: always 0
 */

int main(void)
{
	int i = 0;
	long j = 1, k = 2, sum = k;

	while (k + j < 4000000)
	{
		k += j;
		if (k % 2 == 0)
			sum += k;
		j = k - j;
		++i;
	}
	printf("%ld", sum);
	printf("\n");
	return (0);
}
