#include "shell.h"

/**
 * execute_command - Executes a command with given arguments.
 * @command: The name of the command to execute.
 * @args: Array of arguments for the command.
 *
 */

void execute_command(char *command, char **args)
{
	char *command_path;
	int i;

	command_path = find_command_path(command);
	if (command_path != NULL)
	{
		pid_t pid = fork();

		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			execve(command_path, args, NULL);
			printf("./shell: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
		free(command_path);
	}
	else if (access(command, X_OK) == 0)
	{
		pid_t pid = fork();

		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			execve(command, args, NULL);
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	else
		printf("./shell: No such file or directory\n");
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}
