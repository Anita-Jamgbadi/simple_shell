#include "simple_shell.h"

/**
 * execute_cmd - executes commands
 *
 * @cmd: command
 * @argv: commands array
 * @env: environment array
 *
 * Return: int
 */

int execute_cmd(char **cmd, char **argv, char **env)
{
	pid_t pid;
	int n = 1;

	if (cmd[0][0] != '/' && cmd[0][0] != '.')
	{
		n = add_path(&(cmd[0]), env);
		if (n == -1)
		{
			_printf(argv[0]);
			_printf(": No such file or directory\n");
			return (0);
		}
	}

	pid = fork();

	if (pid == 0)
	{
		execve(cmd[0], cmd, env);
		_printf(argv[0]);
		_printf(": No such file or directory\n");
		free(cmd[0]);
		exit(0);
	}
	else
	{
		wait(NULL);
		if (n == 1 || n == -1)
			return (0);
		free(cmd[0]);
	}
	return (0);
}
