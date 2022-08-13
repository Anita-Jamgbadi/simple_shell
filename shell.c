#include "simple_shell.h"

/**
 * main - begins the shell
 *
 * @argc: ag counter
 * @argv: args array
 * @env: environment array
 *
 * Return: 0
 */

int main(int argc, char **argv, char **env)
{
	char *buf = NULL;
	int status;
	size_t buflen = 0;
	char *cmd[100];

	(void)argc;

	do {
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		readline(&buf, &buflen);

		if (_strcmp(buf, "exit\n") == 0)
		{
			free(buf);
			exit(0);
		}
		if (buf[0] == '\0' || _strcmp(buf, "\n") == 0)
			continue;
		if (_strcmp(buf, "env\n") == 0)
		{
			print_env(env);
			continue;
		}
		parser(buf, cmd);
		if (cmd[0] == NULL)
			continue;

		if (_strcmp(cmd[0], "exit") == 0 && get_arr_len(cmd) == 2)
		{
			status = atoi(cmd[1]);
			free(buf);
			exit(status);
		}
		execute_cmd(cmd, argv, env);
	} while (1);

	return (0);
}
