#include "simple_shell.h"

/**
 * _getenv - gets the environment
 *
 * @target: target
 * @env: environment
 * Return: string
 *
 */

char *_getenv(char *target, char **env)
{
	int i = 0;
	char *path;

	while (env[i])
	{
		if (strncmp(env[i], target, _strlen(target)) == 0)
		{
			path = strdup(env[i]);

			return (path);
		}
		i++;
	}

	return (NULL);
}
