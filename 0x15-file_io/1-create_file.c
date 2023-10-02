#include "main.h"

/**
 * create_file - function that Create and write content
 * @filename: The name of the file to be created.
 * @text_content: The content to be written into the file.
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int file_discript;
	int num_letters;
	int bytes_written;

	if (!filename)
		return (-1);

	file_discript = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_discript == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	num_letters = 0;
	while (text_content[num_letters])
		num_letters++;

	bytes_written = write(file_discript, text_content, num_letters);

	if (bytes_written == -1)
		return (-1);

	close(file_discript);

	return (1);
}
