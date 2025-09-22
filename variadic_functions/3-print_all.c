#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	int first = 1;
	char *s;

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			if (!first)
				printf(", ");
			printf("%c", va_arg(ap, int));
			first = 0;
			break;
		case 'i':
			if (!first)
				printf(", ");
			printf("%d", va_arg(ap, int));
			first = 0;
			break;
		case 'f':
			if (!first)
				printf(", ");
			printf("%f", va_arg(ap, double));
			first = 0;
			break;
		case 's':
			if (!first)
				printf(", ");
			s = va_arg(ap, char *);
			if (!s)
				s = "(nil)";
			printf("%s", s);
			first = 0;
			break;
		default:
			break;
		}
		i++;
	}

	va_end(ap);
	printf("\n");
}
