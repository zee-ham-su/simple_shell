#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/**
 * executecommand - Execute a command.
 * @command: The command to be executed.
 * @argv: Array of command-line arguments.
 * @path: Colon-separated list of directories in the PATH environment variable.
 *
 * This function attempts to execute the specified command by searching for its
 * executable in the given path. If the command is found,
 * it is executed using the
 * execve system call.
 */

void executecommand(char *command, char *argv[], char *path)
{
    char command_path[256] = "";
    size_t command_path_length = 0;
    int found = 0;
    char *dir;

    if (command != NULL && argv != NULL)
    {
        if (command[0] == '/' || command[0] == '.')
        {
            if (execve(command, argv, environ) == -1)
            {
                perror("execve");
            }
        }
        else
        {
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
    }
}
