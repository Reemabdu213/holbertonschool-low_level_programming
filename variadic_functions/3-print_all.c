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
	unsigned int i = 0, j;
	char *str, *sep = "";

	typedef struct printer
	{
		char t;
		void (*f)(va_list, char *);
	} printer;

	void print_char(va_list ap, char *sep) { printf("%s%c", sep, va_arg(ap, int)); }
	void print_int(va_list ap, char *sep) { printf("%s%d", sep, va_arg(ap, int)); }
	void print_float(va_list ap, char *sep) { printf("%s%f", sep, va_arg(ap, double)); }
	void print_string(va_list ap, char *sep)
	{
		char *s = va_arg(ap, char *);
		if (s == NULL)
			s = "(nil)";
		printf("%s%s", sep, s);
	}

	printer funcs[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string}
	};

	va_start(ap, format);

	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == funcs[j].t)
			{
				funcs[j].f(ap, sep);
				sep = ", ";
			}
			j++;
		}
		i++;
	}

	va_end(ap);
	printf("\n");
}
