#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * executeAbsoluteCommand - Executes an absolute command.
 * @command: The command to be executed.
 * @argv: Array of command-line arguments.
 *
 * This function attempts to execute the specified command using execve.
 * It is called when the command is an absolute path
 *     (starts with '/' or '.').
 */

void executeAbsoluteCommand(char *command, char *argv[])
{
    /* betty: function executes an absolute command */
if (execve(command, argv, environ) == -1)
{
perror("execve");
}
}


/**
 * executeCommandInPath - Executes a command in the given path.
 * @command: The command to be executed.
 * @argv: Array of command-line arguments.
 * @path: Colon-separated list of directories in the
 * PATH environment variable.
 *
 * This function searches for the command in the specified path,
 * constructs the command path, and attempts to execute
 * the command using execve.
 */



void executeCommandInPath(char *command, char *argv[], char *path)
{
    /* betty: function executes a command in the given path */
char command_path[256] = "";
size_t command_path_length = 0;
int found = 0;
char *dir;

char path_copy[256];
strncpy(path_copy, path, sizeof(path_copy));
path_copy[sizeof(path_copy) - 1] = '\0';

dir = strtok(path_copy, ":");

while (dir != NULL)
{
command_path_length = strlen(dir);
if (command_path_length + 1 + strlen(command) < sizeof(command_path))
{
strncpy(command_path, dir, sizeof(command_path) - command_path_length - 1);
strncat(command_path, "/", sizeof(command_path) - strlen(command_path) - 1);
command_path_length += 1;
strncat(command_path, command, sizeof(command_path) - command_path_length - 1);
if (execve(command_path, argv, environ) != -1)
{
found = 1;
break;
}
}
else
{
fprintf(stderr, "Command path length exceeded buffer size\n");
break;
}
dir = strtok(NULL, ":");
}

if (!found)
{
fprintf(stderr, "Executable not found: %s\n", command);
}
}


/**
 * executecommand - Execute a command.
 * @command: The command to be executed.
 * @argv: Array of command-line arguments.
 * @path: Colon-separated list of directories in the
 * PATH environment variable.
 *
 * This function determines whether the command is an absolute command
 * or needs to be searched in the specified path.
 * It then calls the appropriate function to execute the command.
 */

void executecommand(char *command, char *argv[], char *path)
{
    /* betty: function executes a command */
if (command != NULL && argv != NULL)
{
if (command[0] == '/' || command[0] == '.')
{
executeAbsoluteCommand(command, argv);
}
else
{
executeCommandInPath(command, argv, path);
}
}
}
