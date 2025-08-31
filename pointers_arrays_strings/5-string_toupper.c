#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 * @s: pointer to the string
 *
 * Return: pointer to the resulting string
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32; /* فرق ASCII بين small و capital */
		}
		i++;
	}
	return (s);
}
