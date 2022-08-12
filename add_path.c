#include "simple_shell.h"

/**
 * add_path - adds path to given command
 *
 * @cmd: command
 * @env: environment
 * Return: int (-1)
 *
 */

int add_path(char **cmd, char **env)
{
	char *path = _getenv("PATH", env), *cmd_path, *ptr;
	struct stat st;

	ptr = strtok(path, ":");

	while (ptr)
	{
		cmd_path = build_path(*cmd, ptr);
		if (stat(cmd_path, &st) == 0)
		{
			*cmd = strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		ptr = strtok(NULL, ":");
	}
	free(path);

	return (-1);
}

/**
 * build_path - builds a path for a given command
 *
 * @cmd: command
 * @path: path
 *
 * Return: built path
 *
 */

char *build_path(char *cmd, char *path)
{
	char *cmd_path;
	int len = strlen(cmd) + strlen(path) + 2;

	cmd_path = malloc(sizeof(*cmd_path) * len);

	if (!cmd_path)
	{
		free(cmd_path);
		return (NULL);
	}

	memset(cmd_path, 0, len);

	_strcpy(cmd_path, path);
	_strcat(cmd_path, "/");
	_strcat(cmd_path, cmd);

	return (cmd_path);
}
