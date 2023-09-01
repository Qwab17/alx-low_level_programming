#include "main.h"

/**
 * _strchr - function that locate a character in a string
 * @s: string to search
 * @c: character to serach
 * Return: s OR NULL
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}
