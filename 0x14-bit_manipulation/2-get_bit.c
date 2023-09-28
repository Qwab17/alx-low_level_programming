#include <stdio.h>
#include "main.h"

/**
 * get_bit - function that Returns value of bit at index.
 * @n: number to extract bit
 * @index: The index of bit from 0.
 * Return: value of the bit or -1 if error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	return ((n >> index) & 1);
}

