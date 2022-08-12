#include "simple_shell.h"

/**
 * readline - reads line from stdin
 *
 * @buf: hold line
 * @buflen: line length
 * Return: n
 *
 */

int readline(char **buf, size_t *buflen)
{
	int n = getline(buf, buflen, stdin);

	if (n == -1)
	{
		free(*buf);
		exit(0);
	}
	return (n);
}
