#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string
 */
void rev_string(char *s)
{
	int i = 0;
	int j = 0;
	char temp;

	/* احسب الطول */
	while (s[j] != '\0')
	{
		j++;
	}
	j--;

	/* بدّل من الطرفين */
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
