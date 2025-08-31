#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: pointer to the string
 */
void print_rev(char *s)
{
	int len = 0;

	/* احسب الطول */
	while (s[len] != '\0')
	{
		len++;
	}

	/* اطبع من الأخير للبداية */
	while (len > 0)
	{
		_putchar(s[len - 1]);
		len--;
	}

	_putchar('\n');
}
