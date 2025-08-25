#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: print the lowercase alphabet in reverse,
 * followed by a new line (using putchar only)
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char c;

for (c = 'z'; c >= 'a'; c--)
putchar(c);

putchar('\n');

return (0);
}
