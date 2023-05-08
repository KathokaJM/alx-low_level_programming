#include "main.h"

/**
 * create_file - create file
 * @filename: Pointer to file name to create
 * @text_content: Pointer to string to be written to file
 *
 * Return: If there is function fail - -1.
 *         otherwise, - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int kj, m, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	kj = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	m = write(kj, text_content, len);

	if (kj == -1 || m == -1)
		return (-1);

	close(kj);

	return (1);
}
