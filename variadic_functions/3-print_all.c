#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * struct printer - maps a format specifier to a print function
 * @t: type specifier
 * @f: function pointer
 */
struct printer
{
	char t;
	void (*f)(va_list, char *);
};

/**
 * p_char - prints a char
 * @ap: argument list
 * @sep: separator printed before the value
 */
static void p_char(va_list ap, char *sep)
{
	printf("%s%c", sep, va_arg(ap, int));
}

/**
 * p_int - prints an int
 * @ap: argument list
 * @sep: separator printed before the value
 */
static void p_int(va_list ap, char *sep)
{
	printf("%s%d", sep, va_arg(ap, int));
}

/**
 * p_float - prints a float
 * @ap: argument list
 * @sep: separator printed before the value
 */
static void p_float(va_list ap, char *sep)
{
	printf("%s%f", sep, va_arg(ap, double));
}

/**
 * p_string - prints a string
 * @ap: argument list
 * @sep: separator printed before the value
 */
static void p_string(va_list ap, char *sep)
{
	char *s = va_arg(ap, char *);

	if (!s)
		s = "(nil)";
	printf("%s%s", sep, s);
}

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
	char *sep = "";
	struct printer funcs[] = {
		{'c', p_char},
		{'i', p_int},
		{'f', p_float},
		{'s', p_string}
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
