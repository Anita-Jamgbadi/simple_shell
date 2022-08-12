#include "simple_shell.h"

/**
 * parser - tokenizes the line from stdin
 *
 * @buf: buffer
 * @cmd: command
 *
 */

void parser(char *buf, char **cmd)
{
	char *ptr;
	int i = 0;

	ptr = strtok(buf, " \t\n\a");

	while (ptr)
	{
		if (ptr[0] == '#')
		{
			cmd[i] = NULL;
			return;
		}

		cmd[i++] = ptr;
		ptr = strtok(NULL, " \t\n\a");
	}
	cmd[i] = NULL;
}
