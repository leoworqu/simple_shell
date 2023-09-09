#include "shell.h"

/**
 * find_command_path - Find the path to a command
 * @command: The command to find the path for
 *
 * Return: The full path to the command, or NULL if not found
 */

char *find_command_path(char *command)
{
	char *path;
	char *path_copy;
	char *token;

	path = getenv("PATH");
	path_copy = strdup(path);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		size_t command_path_length;
		char *command_path;

		command_path_length = strlen(token) + strlen(command) + 2;
		command_path = (char *)malloc(command_path_length);

		strcpy(command_path, token);
		strcat(command_path, "/");
		strcat(command_path, command);

		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}
		free(command_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
