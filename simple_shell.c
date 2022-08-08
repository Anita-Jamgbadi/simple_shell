#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

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
	size_t len = 1;
	int tokens;
	char *token;
	char token_list[20][20];

	line = malloc(len * sizeof(char *)) ;

	do{
		printf("$ ");

		if (getline(&line, &len, stdin) == -1)
		{
			printf("Failed to get line from stdin\n");
		}

		token = strtok(line, " ");
		while (token != NULL)
		{
			strcpy(token_list[tokens], token);
			tokens++;
			token = strtok(NULL, " ");
		}
		args[1] = token_list[0];

		pid = fork();

		if (pid == -1)
		{
			perror("$ Could not fork!\n");
		}
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("$ Did not execute\n");
			}
		}
		wait(&status);
	} while (line == 0);

	return (0);
}
