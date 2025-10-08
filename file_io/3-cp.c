#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * close_fd - Close a file descriptor and handle error
 * @fd: file descriptor to close
 *
 * If close fails, prints error and exits with code 100.
 */
static void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_src - Open source file for reading
 * @path: source path
 *
 * Return: file descriptor on success.
 * If open fails, prints error and exits with code 98.
 */
static int open_src(const char *path)
{
	int fd = open(path, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", path);
		exit(98);
	}
	return (fd);
}

/**
 * open_dst - Open (create/truncate) destination file for writing
 * @path: destination path
 *
 * Return: file descriptor on success.
 * If open fails, prints error and exits with code 99.
 */
static int open_dst(const char *path)
{
	int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", path);
		exit(99);
	}
	return (fd);
}

/**
 * copy_stream - Copy bytes from one fd to another with error handling
 * @from: source fd
 * @to: destination fd
 * @src: source path (for messages)
 * @dst: destination path (for messages)
 *
 * Exits with 98 on read error, 99 on write error.
 */
static void copy_stream(int from, int to, const char *src, const char *dst)
{
	ssize_t r, w;
	char buf[BUF_SIZE];

	while ((r = read(from, buf, sizeof(buf))) > 0)
	{
		w = write(to, buf, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dst);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}
}

/**
 * main - Copy the content of a file to another file
 * @argc: argument count
 * @argv: argument vector (file_from, file_to)
 *
 * Return: 0 on success.
 * Exits with:
 *   97 on usage error,
 *   98 on read error,
 *   99 on write error,
 *   100 on close error.
 */
int main(int argc, char *argv[])
{
	int from, to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from = open_src(argv[1]);
	to = open_dst(argv[2]);

	copy_stream(from, to, argv[1], argv[2]);

	close_fd(from);
	close_fd(to);
	return (0);
}

