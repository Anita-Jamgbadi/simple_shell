#include "simple_shell.h"

/**
 * _env - functions prints the current environment
 * Return:number of env variables
 */

int _env(void)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
