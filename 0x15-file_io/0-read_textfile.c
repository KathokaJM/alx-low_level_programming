#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- read the text file then prints STDOUT
 * @filename: the text file under reading
 * @letters: letters to be read
 * Return: m- real number of bytes to read & print
 *        0 if function fails or NULL filename
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t kj;
	ssize_t m;
	ssize_t n;

	kj = open(filename, O_RDONLY);
	if (kj == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	n = read(kj, buf, letters);
	m = write(STDOUT_FILENO, buf, n);

	free(buf);
	close(kj);
	return (m);
}
