#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <limits.h>

/**
 * struct builtins - struct that points name to a function
 * @funcname:function name
 * @f:function to run
 */

typedef struct builtins
{
	char *funcname;
	int (*f)();
} builtins_t;

char **getTokens(char *buffer);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strsub(char *str, char *search);
int _strcmp(char *first, char *second);
int _envGet(char *s);
int _env(void);
int _shellexit(void);
int execute(char **argsV);

extern char **environ;
#endif /* SIMPLE_SHELL_H*/
