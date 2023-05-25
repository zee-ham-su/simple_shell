#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include <unistd.h>

/**
 * printEnvironment - Prints the environment variables to
 *     the standard output.
 * This function iterates through the environment array and
 *      displays each variable
 * in the format "variable=value".
 *
 * Parameters:
 *    None
 *
 * Returns:
 *    None
 */

void printEnvironment(void)
{

char **env = environ;

while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}
