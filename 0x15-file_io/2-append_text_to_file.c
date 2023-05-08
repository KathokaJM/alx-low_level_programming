#include "main.h"

/**
 * append_text_to_file - append text at file end
 * @filename: pointer to file name
 * @text_content: String to add at file end
 *
 * Return: If function fail or NULL filename - -1.
 *         If the file has no existing user lacks, then write permissions - -1.
 *         otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int k, j, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	k = open(filename, O_WRONLY | O_APPEND);
	j = write(k, text_content, len);

	if (k == -1 || j == -1)
		return (-1);

	close(k);

	return (1);
}
