#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * print_usage - prints usage error and exits 97
 */
static void print_usage(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * err_read - prints read error and exits 98
 * @file: filename
 */
static void err_read(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * err_write - prints write error and exits 99
 * @file: filename
 */
static void err_write(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * err_close - prints close error and exits 100
 * @fd: file descriptor
 */
static void err_close(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * main - copies content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buf[BUF_SIZE];

	if (ac != 3)
		print_usage();

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		err_read(av[1]);

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		err_write(av[2]);
	}

	while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			close(fd_from);
			close(fd_to);
			err_write(av[2]);
		}
	}

	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		err_read(av[1]);
	}

	if (close(fd_from) == -1)
		err_close(fd_from);
	if (close(fd_to) == -1)
		err_close(fd_to);

	return (0);
}
