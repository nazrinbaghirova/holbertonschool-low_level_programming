#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * err - prints error message and exits
 * @code: exit code
 * @name: filename (or NULL)
 * @fd: file descriptor (for close error)
 */
void err(int code, char *name, int fd)
{
	if (code == 97)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	else if (code == 98)
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", name);
	else if (code == 99)
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", name);
	else if (code == 100)
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
	exit(code);
}

/**
 * copy_data - copies file content
 * @fd_from: source fd
 * @fd_to: destination fd
 * @av: argument vector
 */
void copy_data(int fd_from, int fd_to, char **av)
{
	ssize_t r, w;
	char buffer[BUF_SIZE];

	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
			err(99, av[2], 0);
	}

	if (r == -1)
		err(98, av[1], 0);
}

/**
 * main - copies content of one file to another
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
		err(97, NULL, 0);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		err(98, av[1], 0);

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		err(99, av[2], 0);

	copy_data(fd_from, fd_to, av);

	if (close(fd_from) == -1)
		err(100, NULL, fd_from);

	if (close(fd_to) == -1)
		err(100, NULL, fd_to);

	return (0);
}

