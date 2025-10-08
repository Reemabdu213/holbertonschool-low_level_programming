#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * die - print error to stderr then exit with code
 * @code: exit status (97/98/99/100)
 * @fmt:  printf-like format
 * @s:    string arg for %s (NULL if using %d)
 * @fd:   int arg for %d (used with close errors)
 */
static void die(int code, const char *fmt, const char *s, int fd)
{
	if (s)
		dprintf(STDERR_FILENO, fmt, s);
	else
		dprintf(STDERR_FILENO, fmt, fd);
	exit(code);
}

/**
 * main - copy file_from into file_to (1024 bytes per read)
 * @ac: argc
 * @av: argv
 *
 * Return: 0 on success, exits with:
 * 97 usage, 98 read error, 99 write error, 100 close error
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, r, w, c1, c2;
	char buf[1024];

	if (ac != 3)
		die(97, "Usage: cp file_from file_to\n", NULL, 0);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		die(98, "Error: Can't read from file %s\n", av[1], 0);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		die(99, "Error: Can't write to %s\n", av[2], 0);
	}

	while ((r = read(fd_from, buf, sizeof(buf))) > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			close(fd_from);
			close(fd_to);
			die(99, "Error: Can't write to %s\n", av[2], 0);
		}
	}

	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		die(98, "Error: Can't read from file %s\n", av[1], 0);
	}

	c1 = close(fd_from);
	if (c1 == -1)
		die(100, "Error: Can't close fd %d\n", NULL, fd_from);

	c2 = close(fd_to);
	if (c2 == -1)
		die(100, "Error: Can't close fd %d\n", NULL, fd_to);

	return (0);
}

