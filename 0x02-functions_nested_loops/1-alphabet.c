#include "main.h"

/**
 * main - function to print alphabet
 * Return: always 0
 */

void print_alphabet(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
		_putchar(i);
	_putchar('\n');
}
