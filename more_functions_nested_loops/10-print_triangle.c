#include "main.h"

/**
 * print_triangle - prints a triangle using the character #
 * @size: the size of the triangle
 */
void print_triangle(int size)
{
int i, j, k;

if (size <= 0)
{
_putchar('\n');
}
else
{
for (i = 1; i <= size; i++)
{
/* اطبع المسافات */
for (j = size - i; j > 0; j--)
{
_putchar(' ');
}
/* اطبع # */
for (k = 1; k <= i; k++)
{
_putchar('#');
}
_putchar('\n');
}
}
}
