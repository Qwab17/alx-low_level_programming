#include "main.h"

/**
 * append_text_to_file - function that Append text
 * @filename: file name  to append
 * @text_content: content to append
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_descript;
	int num_letters;
	int bytes_written;

	if (!filename)
		return (-1);

	file_descript = open(filename, O_WRONLY | O_APPEND);

	if (file_descript == -1)
		return (-1);

	if (text_content)
	{
		num_letters = 0;
		while (text_content[num_letters])
			num_letters++;

		bytes_written = write(file_descript, text_content, num_letters);

		if (bytes_written == -1)
			return (-1);
	}

	close(file_descript);

	return (1);
}
