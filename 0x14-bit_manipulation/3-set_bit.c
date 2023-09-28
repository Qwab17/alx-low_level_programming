#include "main.h"

/**
 * set_bit - function that Sets value of bit to 1
 * @n: Pointer to the number
 * @index: The index from 0.
 * Return: 1 if it worked, or -1 if error
 */

#include "main.h"

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	bit_mask = 1UL << index;
	*n = *n | bit_mask;

	return (1);
}
