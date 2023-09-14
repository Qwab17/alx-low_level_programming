#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

/**
 * print_all - function that prints anything
 * @format: list of arguments types passed to the function
 */

void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *seprt = "";

	va_list list;

	va_start(list, format);
	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", seprt, va_arg(list, int));
					break;
				case 'i':
					printf("%s%d", seprt, va_arg(list, int));
					break;
				case 'f':
					printf("%s%f", seprt, va_arg(list, double));
					break;
				case 's':
					str = va_arg(list, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", seprt, str);
					break;
				default:
					i++;
					continue;
			}
			seprt = ", ";
			i++;
		}
	}
	printf("\n");
	va_end(list);
}
