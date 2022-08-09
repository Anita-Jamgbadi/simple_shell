#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>

/**
 * getpath - function gets the absolute path
 *@buf:buffer for the function
 *@size:size of information
 *Return(0)
 */

char *getpath()
{
	char cwd[PATH_MAX];
	char *path = getcwd(cwd, sizeof(cwd));

	if (path == NULL)
		perror("Cannot get the path");
	chmod(path, S_IWOTH);	
	return (path);
}

/**
 * main - Implementation of a basic shell. it displays a prompt,
 * waits for a command (no, args)
 *
 * Return: 0 on success
 */


int main()
{
	int status;
	pid_t pid;
	char *line;
	char *args[3] = {"NULL", "NULL", "NULL"};
	int len = 1024;
	size_t len2 = 0;
	int tokens;
	char *token;
	char *token_list[2];
	
	line = malloc(len * sizeof(char *)) ;
	
	if (line == NULL)
		exit(0);
	do{
		printf("$ ");

		if (getline(&line, &len2, stdin) == -1)
		{
			printf("Failed to get line from stdin\n");
		}

		tokens = 0;
		token = strtok(line, " ");
		while (token != NULL)
		{
			strcpy(token_list[tokens], token);
			tokens++;
			token = strtok(NULL, " ");
		}
		args[0] = "/simple/ls";
		/*printf("Path: %s\n", args[0]);*/
		args[1] = token_list[0];

		pid = fork();

		if (pid == -1)
		{
			perror("$ Could not fork!\n");
		}
		if (pid == 0)
		{
			if (execv(args[0], args) == -1)
			{
				perror("$ Did not execute ");
			}
		}
	
	} while (wait(&status));

	return (0);
}
