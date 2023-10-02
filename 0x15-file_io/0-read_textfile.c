#include "main.h"

/**
 * read_textfile - function that reads a text file and prints
 * @filename: file to read
 * @letters: letters to read and print
 * Return: number of letters to print, if cannot read, return 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t bytes_read = 0;
	ssize_t bytes_written = 0;
	int file_dp = open(filename, O_RDONLY); /* read-only mode */

	if (filename == NULL)
		return (0);

	buffer = malloc(letters); /* Allocate memory */

	if (file_dp == -1)
	{
		free(buffer);
		return (0); /* fail to read */
	}

	bytes_read = read(file_dp, buffer, letters); /* Read file */
	if (bytes_read == -1)
	{
		free(buffer);
		close(file_dp);
		return (0); /* fail to write */
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read); /* Write */
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		close(file_dp);
		return (0); /* fail to write */
	}

	free(buffer);
	close(file_dp);
	return (bytes_written); /* Return letters printed */
}
