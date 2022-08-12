#include "simple_shell.h"

/**
 * _strsub - function is used to search for a string
 * @str:string to search in
 * @search:string to search for
 * Return:pointer to where the match is
 */

char *_strsub(char *str, char *search)
{
	int a, b, c, i;
	char *s, *cpy;

	cpy = malloc(sizeof(char) * _strlen(str));
	_strcpy(cpy, str);
	b = 0;
	while (*str)
	{
		b++;
		str++;
	}

	a = i = 0;
	while (i < b)
	{
		if (cpy[i] == search[i])
		{
			a++;
			i++;
		}
		else
			i++;
		if (*(search + i) == '\0')
			break;
	}

	s = malloc(sizeof(char) * (b - a));
	if (s == NULL)
		return (0);
	c = 0;
	while (cpy[a] != '\0')
	{
		s[c] = cpy[a];
		c++;
		a++;
	}
	s[c] = '\0';
	return (s);
}
