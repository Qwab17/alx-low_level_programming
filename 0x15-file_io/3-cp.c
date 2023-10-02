#include "main.h"

int main(int argc, char *argv[]);

/**
 * main - function that copy content of file to other
 * @argc: arguments count
 * @argv: argument vector
 * Return: 0 on success, or exit error
 */

int main(int argc, char *argv[])
{
	int file_source, file_dest;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_source file_dest\n", argv[0]);
		exit(97);
	}

	file_source = open(argv[1], O_RDONLY);
	if (file_source == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_dest == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((bytes_read = read(file_source, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_dest, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(file_source) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_source);
		exit(100);
	}

	if (close(file_dest) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_source);
		exit(100);
	}

	return (0);
}
