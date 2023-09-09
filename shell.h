#ifndef Head
#define Head

#define MAX_LENGTH 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char *command, char **args);
char *find_command_path(char *command);
char **parse_arguments(char *command);

#endif
