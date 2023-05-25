#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * prompt - prints,scan, execute and loop.
 * 
 * @shellName: name of the shell
 *
 * void
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
write(STDOUT_FILENO, shellName, strlen(shellName));
write(STDOUT_FILENO, "@ ", 2);
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
write(STDOUT_FILENO, "\n", 1);
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
write(STDOUT_FILENO, "Exiting the shell...\n", 21);
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
write(STDOUT_FILENO, "Command received: ", 18);
write(STDOUT_FILENO, cmd, strlen(cmd));
write(STDOUT_FILENO, "\n", 1);

tokenizeCommand(cmd, argv, &argc);
write(STDOUT_FILENO, "Tokenized arguments: ", 21);
for (i = 0; i < argc; i++)
{
write(STDOUT_FILENO, argv[i], strlen(argv[i]));
write(STDOUT_FILENO, " ", 1);
}
write(STDOUT_FILENO, "\n", 1);

child_id = fork();
if (child_id == -1)
{
free (cmd);
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
