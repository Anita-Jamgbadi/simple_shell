#include "simple_shell.h"

/**
 * print_env - print environment
 *
 * @env: environment
 *
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		_printf(env[i++]);
		_printf("\n");
	}
}
