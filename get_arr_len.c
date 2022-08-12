#include "simple_shell.h"

/**
 * get_arr_len - gets the length of an array
 *
 * @cmd: command
 * Return: i;
 *
 */

int get_arr_len(char **cmd)
{
	int i = 0;

	while (cmd[i])
		i++;

	return (i);
}
