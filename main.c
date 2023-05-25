#include "shell.h"
/**
 * main - Simple shell; prints the prompt with the shell
 * name.
 * Return: Always 0.
 */
int main(void)
{
	char **env = NULL;
	char *shellName = "MyShell";

	prompt(shellName, env);

	return (0);
}
