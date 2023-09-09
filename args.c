#include "shell.h"

/**
 * parse_arguments - Parse the arguments from a command string
 * @command: The command string to parse
 *
 * Return: A double pointer containing the parsed arguments
 */

char **parse_arguments(char *command)
{
	char **args;
	char *token;
	int i;

	args = (char **)malloc(MAX_LENGTH * sizeof(char *));
	token = strtok(command, " ");
	i = 0;

	while (token != NULL)
	{
		args[i] = (char *)malloc(strlen(token) + 1);
		strcpy(args[i], token);
		token = strtok(NULL, " ");
		i++;
	}

	args[i] = NULL;

	return (args);
}
