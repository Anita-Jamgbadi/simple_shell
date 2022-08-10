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
 * main - executes a given command
 *
 * Return: 0 on success
 */

char **environ;

int main()
{
	char *line, *line_cpy, *token, *path = "/bin/";
	size_t line_count_1;
	ssize_t line_count;
	int tokens, i;
	char **argsV;
	pid_t pid;

	
	do{

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

		printf("You entered: %s\n", line);
		line_cpy = malloc(sizeof(char) * strlen(line));
		strcpy(line_cpy, line);

		printf("line_cpy: %s\n", line_cpy);
		/** Count tokens in line **/
		tokens = i = 0;
		token = strtok(line, " ");
		while (token != NULL)
		{
			tokens++;
			token = strtok(NULL, " ");
		}
		tokens++;

		argsV = malloc(sizeof(char *) * tokens);

		/** Push Tokens into argsV **/

		token = strtok(line_cpy, " ");
		while (token != NULL)
		{
			if (i == 0)
			{
				argsV[i] = malloc((sizeof(char)) * (strlen(token) + strlen(path)));
				strcat(argsV[i], path);
				strcat(argsV[i], token);
				printf("%s\n", argsV[i]);
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

		printf("Tokens entered: %d\n", i);

		pid = fork();

		if (pid == -1)
		{
			perror("unable to make a baby '^': ");
		}
		if (pid == 0)
		{
			if(execve(argsV[0], &argsV[0], environ) == -1)
			{
				perror("Did not execute: ");
			}
			return (0);
		}

		free(line);
		free(argsV);
		free(line_cpy);

	} while(wait(&pid));
	return (0);
}
