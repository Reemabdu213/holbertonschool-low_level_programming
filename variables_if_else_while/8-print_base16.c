#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: print all numbers of base 16 in lowercase,
 * followed by a new line (using putchar only)
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int n;
char c;

for (n = 0; n < 10; n++)
putchar(n + '0');

for (c = 'a'; c <= 'f'; c++)
putchar(c);

putchar('\n');

return (0);
}
