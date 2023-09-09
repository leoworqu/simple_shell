#include "shell.h"

/**
 * main - Entry point
 *
 * Description: Executes a command line interface for user commands
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *command;
	size_t command_length;
	ssize_t read;
	char **args;

	command = NULL;
	command_length = 0;

	while (1)
	{
		fflush(stdout);

		read = getline(&command, &command_length, stdin);
		if (read == -1)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		args = parse_arguments(command);
		execute_command(args[0], args);
	}
	free(command);
	return (0);
}
