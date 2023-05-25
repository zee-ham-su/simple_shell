#include "shell.h"

int main(void) 
{
  char **env = NULL;
  char *shellName = "MyShell";
  prompt(shellName, env);
  return 0;
}