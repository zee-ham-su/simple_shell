#include "shell.h"
/**
 * main - Simple shell; prints the prompt with the shell
 * name.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	/*char **env = NULL;*/
	char *shellName = "MyShell";
FILE *input_file;
int i;

if (argc > 1)
{

if (strcmp(argv[1], "-f") == 0 && argc > 2)
{


input_file = fopen(argv[2], "r");
if (input_file == NULL)
{
perror("Error opening input file");
exit(EXIT_FAILURE);
}

fclose(input_file);
}
else
{

for (i = 1; i < argc; i++)
{
printf("Argument %d: %s\n", i, argv[i]);
}
}
}
else
{

prompt(shellName);
}
return (0);
}
