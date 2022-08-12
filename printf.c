#include "simple_shell.h"

/**
 * _printf - prints to stdout
 *
 * @s: char to be printed to stdout
 *
 * Return: char count
 */

int _printf(char *s)
{
	int cnt = 0;

	while (*s)
	{
		cnt += write(1, s, 1);
		s++;
	}
	return (cnt);
}
