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
 * getTokens - function is used to tokenize strings
 * @line:buffer to be tokenized
 * Return:0
 */

char **getTokens(char *buffer)
{
	char *line_cpy, *token, **argsV, *path = "/bin/";
	int tokens, i;

	line_cpy = malloc(sizeof(char) * strlen(buffer));
	strcpy(line_cpy, buffer);
	tokens = i = 0;
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		tokens++;
		token = strtok(NULL, " ");
	}
	tokens++;

	argsV = malloc(sizeof(char *) * tokens);

	token = strtok(line_cpy, " ");
	while (token != NULL)
	{
		if (i == 0)
		{
			argsV[i] = malloc((sizeof(char)) * (strlen(token) + strlen(path)));
			strcat(argsV[i], path);
			strcat(argsV[i], token);
		}
		else
		{
			argsV[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argsV[i], token);
		}
		i++;
		token = strtok(NULL, " ");
	}
	argsV[i] = NULL;
	return (argsV);
}

/**
 * main - executes a given command
 *
 * Return: 0 on success
 */

int main(void)
{
	char *line, **argsV;
	size_t line_count_1;
	ssize_t line_count;
	pid_t pid;


	do {

		/** Display Prompt **/
		printf("$ ");

		line_count_1 = 0;
		line_count = getline(&line, &line_count_1, stdin);

		/* check for EOF */

		if (line_count == -1)
		{
			perror("Goodbye '_' ...");
			return (0);
		}

		argsV = getTokens(line);
		pid = fork();

		if (pid == -1)
		{
			perror("unable to make a baby '^': ");
		}
		if (pid == 0)
		{
			if (execve(argsV[0], argsV, NULL) == -1)
			{
				perror("Did not execute: ");
			}
			return (0);
		}

		free(line);
		free(argsV);
	} while (wait(&pid));
	return (0);
}
