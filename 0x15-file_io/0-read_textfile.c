#include "main.h"
/**
 * read_textfile - reads text file and prints it to stdout
 * @filename: Name of file to be read
 * @letters: exact number of letter to be printed
 * Return: 0 if it fails, else the number of characters
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	/* Declare variables to be used */
	int fd;
	ssize_t numread, numwrit;
	char *buf;

	if (filename == NULL)
		return (0);
	/* open file */
	fd = open(filename, O_RDONLY);
	/* check if file opens */
	if (fd == -1)
		return (0);
	/* malloc space */
	buf = malloc(letters);
	if (buf == NULL)
		return (0);
	/* Now proceed to read the text file */
	numread = read(fd, buf, letters);
	/* write to stdout */
	numwrit = write(STDOUT_FILENO, buf, numread);
	free(buf);
	close(fd);
	return (numwrit);
}
