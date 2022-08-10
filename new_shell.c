#include "simple_shell.h"

/**
 * getTokens - function is used to tokenize strings
 * @buffer:buffer to be tokenized
 * Return:0
 */

char **getTokens(char *buffer)
{
	char *line_cpy, *token, **argsV, *path = "";
	int tokens, i;

	line_cpy = malloc(sizeof(char) * strlen(buffer));
	if (line_cpy == NULL)
		perror("./hsh");
	strcpy(line_cpy, buffer);
	tokens = i = 0;
	token = strtok(buffer, " \n");
	while (token != NULL)
	{
		tokens++;
		token = strtok(NULL, " \n");
	}
	tokens++;

	argsV = malloc(sizeof(char *) * tokens);
	if (argsV == NULL)
		perror("./hsh");
	token = strtok(line_cpy, " \n");
	while (token != NULL)
	{
		if (i == 0)
		{
			argsV[i] = malloc((sizeof(char)) * (strlen(token) + strlen(path)));
			if (argsV[i] == NULL)
				perror("./hsh");
			strcat(argsV[i], path);
			strcat(argsV[i], token);
		}
		else
		{
			argsV[i] = malloc(sizeof(char) * strlen(token));
			if(argsV[i] == NULL)
				perror("./hsh");
			strcpy(argsV[i], token);
		}
		i++;
		token = strtok(NULL, " \n");
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
		printf("$ ");

		line_count_1 = 0;
		line_count = getline(&line, &line_count_1, stdin);

		if (line_count == -1)
		{
			return (0);
		}

		argsV = getTokens(line);
		pid = fork();

		if (pid == -1)
		{
			perror("./hsh");
		}
		if (pid == 0)
		{	
			if (execve(argsV[0], argsV, environ) == -1)
			{
				perror("./hsh");
			}
			return (0);
		}

		free(line);
		free(argsV);
	} while (wait(&pid));
	return (0);
}
