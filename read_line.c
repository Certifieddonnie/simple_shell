#include "shell.h"

/**
 * read_line - reads the input string.
 * @i_eof: returns value of getline function
 * Return: input string.
 */
char *read_line(int *i_eof)
{
	char *entry = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&entry, &bufsize, stdin);

	return (entry);
}
