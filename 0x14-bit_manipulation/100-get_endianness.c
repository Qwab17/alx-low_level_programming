#include "main.h"

/**
 * get_endianness - function that Checks the endian
 * Return: 0 on big endian or 1 on little endian.
 */

int get_endianness(void)
{
	unsigned int value = 1;
	char *byte = (char *)&value;

	if (*byte == 1)
	{
		return (1); /* on little Endian */
	}
	else
	{
		return (0); /* on big endian */
	}
}
