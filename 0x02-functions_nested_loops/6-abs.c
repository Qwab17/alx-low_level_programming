#include "main.h"

/**
 * _abs - compute absolute value
 * @a: function parameter
 * Return: always -a or a;
 */

int _abs(int a)
{
	if (a < 0)
		return (-a);
	else if (a >= 0)
	{
		return (a);
	}
	return (0);
}
