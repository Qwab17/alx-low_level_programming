#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - function that Converts binary to unsigned integer
 * @b: Pointer to a string
 * Return: converted number or 0 if invalid
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int q = 0;
	char current_char;

	if (b == NULL)
	{
		return (0);
	}

	for (q = 0; b[q] != '\0'; q++)
	{
		current_char = b[q];

		if (current_char == '0')
		{
			result = result << 1;
		}
		else if (current_char == '1')
		{
			result = (result << 1) | 1;
		}
		else
		{
			return (0);
		}
	}

	return (result);
}
