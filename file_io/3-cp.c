#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * print_exit - Print an error message to stderr then exit with code.
 * @code: exit status to use.
 * @fmt:  printf-like format string.
 * @sarg: string argument for %s (or NULL if not used).
 * @iarg: int argument for %d   (used حين نطبع fd في close).
 *
 * Description: Small helper to avoid code duplication and keep Betty happy.
 */
static void print_exit(int code, const char *fmt, const char *sarg, int iarg)
{
	if (sarg)
		dprintf(STDERR_FILENO, fmt, sarg);
	else
		dprintf(STDERR_FILENO, fmt, iarg);
	exit(code);
}

/**
 * main - Copy the content of a file to another file.
 * @ac: argument count.
 * @av: argument vector (av[1]=file_from, av[2]=file_to).
 *
 * Return: 0 on success. Exits with:
 * 97 on wrong usage, 98 on read error, 99 on write error,
 * 100 on close error.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, r, w, c1, c2;
	char buf[1024];

	if (ac != 3)
		print_exit(97, "Usage: cp file_from file_to\n", NULL, 0);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		print_exit(98, "Error: Can't read from file %s\n", av[1], 0);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_exit(99, "Error: Can't write to %s\n", av[2], 0);
	}

	while (1)
	{
		r = read(fd_from, buf, sizeof(buf));
		if (r == -1) /* لازم نوقف هنا ونطلع 98 قبل أي write */
		{
			close(fd_to);
			close(fd_from);
			print_exit(98, "Error: Can't read from file %s\n", av[1], 0);
		}
		if (r == 0) /* EOF */
			break;

		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			close(fd_to);
			close(fd_from);
			print_exit(99, "Error: Can't write to %s\n", av[2], 0);
		}
	}

	c1 = close(fd_from);
	if (c1 == -1)
		print_exit(100, "Error: Can't close fd %d\n", NULL, fd_from);

	c2 = close(fd_to);
	if (c2 == -1)
		print_exit(100, "Error: Can't close fd %d\n", NULL, fd_to);

	return (0);
}
