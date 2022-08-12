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


int _printf(char *s);
int get_arr_len(char **cmd);
void print_env(char **env);
int readline(char **buf, size_t *buflen);
void parser(char *buf, char **cmd);
char *_getenv(char *target, char **env);
char *build_path(char *cmd, char *path);
int add_path(char **cmd, char **env);
int execute_cmd(char **cmd, char **argv, char **env);
int main(int argc, char **argv, char **env);

/*
 * string manipulation files
 */
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strsub(char *str, char *search);

extern char **environ;
#endif /* SIMPLE_SHELL_H*/
