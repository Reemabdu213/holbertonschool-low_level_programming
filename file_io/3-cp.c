#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

/**
 * print_error_and_exit - print error message to stderr and exit with code
 * @code: exit code
 * @fmt:  format string
 * @arg:  single string/int argument for the format
 */
static void print_error_and_exit(int code, const char *fmt, int arg_is_fd, const char *arg_s, int arg_fd)
{
	if (arg_is_fd)
		dprintf(STDERR_FILENO, fmt, arg_fd);
	else
		dprintf(STDERR_FILENO, fmt, arg_s);
	exit(code);
}

/**
 * main - copies the content of a file to another
 * @ac: argument count
 * @av: argument values
 *
 * Return: 0 on success, exits with specific codes on error
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, r, w, c1, c2;
	char buf[1024];

	if (ac != 3)
		print_error_and_exit(97, "Usage: cp file_from file_to\n", 0, NULL, 0);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit(98, "Error: Can't read from file %s\n", 0, av[1], 0);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error_and_exit(99, "Error: Can't write to %s\n", 0, av[2], 0);
	}

	while (1)
	{
		r = read(fd_from, buf, sizeof(buf));
		if (r == -1) /* read failure -> 98 */
		{
			close(fd_to);
			close(fd_from);
			print_error_and_exit(98, "Error: Can't read from file %s\n", 0, av[1], 0);
		}
		if (r == 0) /* EOF */
			break;

		w = write(fd_to, buf, r);
		if (w == -1 || w != r) /* write failure -> 99 */
		{
			close(fd_to);
			close(fd_from);
			print_error_and_exit(99, "Error: Can't write to %s\n", 0, av[2], 0);
		}
	}

	c1 = close(fd_from);
	if (c1 == -1)
		print_error_and_exit(100, "Error: Can't close fd %d\n", 1, NULL, fd_from);

	c2 = close(fd_to);
	if (c2 == -1)
		print_error_and_exit(100, "Error: Can't close fd %d\n", 1, NULL, fd_to);

	return (0);
}
