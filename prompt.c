#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/**
 * prompt - Display the shell prompt and handle user commands.
 * @shellName: Name of the shell.
 *
 * This function displays the shell prompt, reads user input, and handles
 * various commands. It continues to prompt
 *     the user until the "exit" command
 * is entered.
 */

void prompt(char *shellName)
{
char *cmd = NULL;
size_t cmd_size = 0;
ssize_t read_line;
char *argv[MAX_ARGS];
pid_t child_id;
int status;
int argc;
int i;
char *path = getenv("PATH");

for (;;)
{
if (isatty(STDIN_FILENO))
{
printf("%s@ ", shellName);
}
read_line = getline(&cmd, &cmd_size, stdin);
if (read_line == -1)
{
if (cmd != NULL)
{
free(cmd);
cmd = NULL;
}
if (feof(stdin))
{
printf("\n");
exit(EXIT_SUCCESS);
}
perror("ERROR");
continue;
}
cmd[strcspn(cmd, "\n")] = '\0';
if (strcmp(cmd, "exit") == 0)
{
if (cmd != NULL)
{
free(cmd);
cmd = NULL;
}
printf("Exiting the shell...\n");
exit(EXIT_SUCCESS);
}
if (strcmp(cmd, "env") == 0)
{
if (cmd != NULL)
{
free(cmd);
cmd = NULL;
}
printEnvironment();
continue;
}

tokenizeCommand(cmd, argv, &argc);

for (i = 0; i < argc; i++)
{
printf("%s ", argv[i]);
}
printf("\n");
printf("Executing command: %s\n", cmd);
child_id = fork();
if (child_id == -1)
{
free(cmd);
exit(EXIT_FAILURE);
}
if (child_id == 0)
{
executecommand(argv[0], argv, path);
}
else
{
waitpid(child_id, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
{
continue;
}
}
if (cmd != NULL)
{
free(cmd);
cmd = NULL;
}
}
}
