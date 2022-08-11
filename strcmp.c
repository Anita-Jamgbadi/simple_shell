#include "simple_shell.h"

/**
 * _strcmp - function compares tw strings
 * @s1:first string
 * @s2:second string
 * Return:0
 */

int _strcmp(char *s1, char *s2)
{
	int a;

	a = 0;

	if (_strlen(s1) != _strlen(s2))
		return (-1);
	while (s1[a] != '\0' || s2[a] != '\0')
	{
		if (s1[a] != s2[a])
			return (-1);
		a++;
	}
	return (0);
}
