#include <stdio.h>

/**
 * main - prints the program name
 * @argc: number of command line arguments
 * @argv: array containing the command line arguments
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}
