#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, NULL if str = NULL or malloc fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* calculate length of str */
	while (str[len] != '\0')
		len++;

	/* allocate memory for copy */
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	/* copy characters */
	for (i = 0; i < len; i++)
		dup[i] = str[i];

	/* add null terminator */
	dup[len] = '\0';

	return (dup);
}
