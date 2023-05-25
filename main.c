#include "shell.h"
/**
 * main - Simple shell; prints the prompt with the shell
 * name.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always 0
 */

int main(void)
{
	/*char **env = NULL;*/
	char *shellName = "MyShell";

prompt(shellName);

return (0);
}
