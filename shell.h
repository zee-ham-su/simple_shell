#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#define MAX_ARGS 10


extern char **environ;
void prompt(char *shellName);
void tokenizeCommand(char *cmd, char *argv[], int *argc);
void executecommand(char *command, char *argv[], char *path);
void printEnvironment(void);
int main(int argc, char *argv[]);

#endif
