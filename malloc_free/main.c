#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer;
	int i;

	buffer = create_array(10, 'R');
	if (buffer == NULL)
	{
		printf("Failed to allocate memory\n");
		return (1);
	}

	for (i = 0; i < 10; i++)
		printf("%c", buffer[i]);
	printf("\n");

	free(buffer);
	return (0);
}
