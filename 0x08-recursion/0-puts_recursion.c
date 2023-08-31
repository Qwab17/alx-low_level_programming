#include "main.h"

/**
 * _puts_recursion - recursive function that prints a string and anew line
 * @s: string to print
 * Return: nothing
 */

void _puts_recursion(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	if (*s == '\0')
	{
		_putchar('\n');
	}
}
