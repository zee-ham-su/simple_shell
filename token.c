#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * tokenizeCommand - Tokenize a command string.
 * @cmd: The command string to be tokenized.
 * @argv: Array to store the command tokens.
 * @argc: Pointer to store the number of command tokens.
 *
 * This function tokenizes the command string by
 * splitting it into individual tokens
 * based on whitespace delimiter.
 * The tokens are stored in the argv array, and the
 * number of tokens is stored in the argc variable.
 */

void tokenizeCommand(char *cmd, char *argv[], int *argc)
{
char *token;
*argc = 0;

for (;;)
{
token = strtok(cmd, " ; ");

if (token == NULL || *argc >= MAX_ARGS - 1)
break;

argv[*argc] = token;
(*argc)++;

cmd = NULL;
}

argv[*argc] = NULL;
}
