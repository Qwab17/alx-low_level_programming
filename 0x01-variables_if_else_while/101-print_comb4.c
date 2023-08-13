#include <stdio.h>

/**
 * main - three digits combination
 *
 * Return: always 0
 */
int main(void)
{
	int hundreds, tens, ones;
	int count = 0;

	for (hundreds = 0; hundreds <= 9; hundreds++)
	{
		for (tens = 0; tens <= 9; tens++)
		{
			for (ones = 0; ones <= 9; ones++)
			{
				if (hundreds != tens && hundreds != ones && tens != ones)
				{
					printf("%d%d%d", hundreds, tens, ones);
					count++;

					if (count != 599)
						{
							putchar(',');
							putchar(' ');
						}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
