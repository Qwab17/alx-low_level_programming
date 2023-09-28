#include "main.h"

/**
 * clear_bit - function that Sets the value of a bit to 0
 * @n: Pointer to the number
 * @index: The index to clear from 0.
 * Return: 1 on success, or -1 if error.
 */

#include "main.h"

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	bit_mask = 1UL << index;
	*n = *n & (~bit_mask);

	return (1);
}
