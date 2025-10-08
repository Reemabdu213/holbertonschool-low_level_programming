#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	ssize_t n;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s <file> <letters>\n", av[0]);
		return (1);
	}

	n = read_textfile(av[1], (size_t)atoi(av[2]));
	dprintf(STDERR_FILENO, "\n[printed bytes]: %ld\n", (long)n);
	return (0);
}
