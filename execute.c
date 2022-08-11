#include "simple_shell.h"

/**
 * execute - function is used to execute the argunments
 * @argsV:arguments to execute
 * Return:0
 */

int execute(char **argsV)
{
	pid_t pid;
	char *s;

	pid = fork();
	if (pid == -1)
	{
		perror("./hsh");
	}
	if (pid == 0)
	{
		if (execve(argsV[0], argsV, environ) == -1)
		{
			s = _strsub("_=./hsh", "_=");
			perror(s);
		}
		_exit(0);
	}
	return (0);
}
