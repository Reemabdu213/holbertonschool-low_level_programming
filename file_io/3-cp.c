#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error_exit - Prints an error message to stderr and exits.
 * @code: Exit status (97, 98, 99, or 100)
 * @fmt: Format string (e.g. "Error: Can't read from file %s\n")
 * @s: String argument for %s (NULL if not used)
 * @fd: Integer argument for %d (used when closing fd)
 */
static void error_exit(int code, const char *fmt, const char *s, int fd)
{
	if (s)
		dprintf(STDERR_FILENO, fmt, s);
	else
		dprintf(STDERR_FILENO, fmt, fd);
	exit(code);
}

/**
 * main - Copies the content of a file to another file.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, r, w, c1, c2;
	char buf[1024];

	if (ac != 3)
		error_exit(97, "Usage: cp file_from file_to\n", NULL, 0);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", av[1], 0);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to %s\n", av[2], 0);
	}

	while ((r = read(fd_from, buf, 1024)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to %s\n", av[2], 0);
		}
	}

	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit(98, "Error: Can't read from file %s\n", av[1], 0);
	}

	c1 = close(fd_from);
	if (c1 == -1)
		error_exit(100, "Error: Can't close fd %d\n", NULL, fd_from);

	c2 = close(fd_to);
	if (c2 == -1)
		error_exit(100, "Error: Can't close fd %d\n", NULL, fd_to);

	return (0);
}
