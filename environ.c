#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include <unistd.h>

/**
 * environ.c - this function prints the environment variables
 *
 * printEnvironment: This function prints the environment variables to
 *
 * the standard output.It iterates through the environment array and
 *
 * displays each variable in the format "variable=value".
 *
 * Parameters: None
 * Returns: None
*/



void printEnvironment(void)
{
char **env = environ;
while (*env != NULL)
{
write(STDOUT_FILENO, *env, strlen(*env));
write(STDOUT_FILENO, "\n", 1);
env++;
}
}
