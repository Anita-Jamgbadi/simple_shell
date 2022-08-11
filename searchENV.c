#include "simple_shell.h"

/**
 * _envGet- function gets the value of the
 * value of a searched env variable
 * @s:key to search for
 * Return: position of the key
 */

int _envGet(char *s)
{
	int a, b;

	a = b = 0;
	while (environ[a])
	{
		while (*s)
		{
			if (*environ[a] == s[a])
			{
				printf("Value: %d\n", a);
				return (a);
			}
			if (s[a] == '\0')
				break;
			s++;
		}
		a++;
	}
	return (0);
}
