#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * prompt - prints,scan, execute and loop.
 * @env: environment
 * @shellName: name of the shell
 *
 * void
 */

void prompt(char *shellName, char **env)
{
	char *cmd = NULL;
	size_t cmd_size = 0;
	ssize_t read_line;
	char *argv[] = {NULL, NULL};
	pid_t child_id;
	int j;
	int status;

	for (;;)
	{
		printf("%s $ ", shellName);
		read_line = getline(&cmd, &cmd_size, stdin);
		if (read_line == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (cmd[j])
		{
			if (cmd[j] == '\n')
			cmd[j] = '\0';
			j++;
		}
		argv[0] = cmd;
		child_id = fork();
		if (child_id == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		if (child_id == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			printf("%s: file or directory missing\n", argv[0]);
		} else
		{
			wait(&status);
		}
	}
}
