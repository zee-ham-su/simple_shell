0x16. C - Simple Shell
INTRO:
This project is collaborated by Sufian Hamza and Gideon Gyebi as part of our ALX-SE program.


PROJECT DESCRIPTION
SIMPLE UNIX SHELL This is a straightforward UNIX command line interpreter implementation. Command line parameters received from standard input can be interpreted and used by the shell for execution. If the command is legitimate, the shell reads lines from a file or terminal line, which are then parsed, and executes them. The shell work in both interacrive and non-interactive modes and can execute basic shell commands.

Prerequisites


Operating System: Any system that supports a shell environment (e.g., Linux, macOS, Windows with Cygwin)
Compiler: GCC (GNU Compiler Collection)


function list and its corresponding definition


printEnvironment(): This function prints the environment variables to the standard output. It iterates through the environ array and displays each variable in the format "variable=value".

executecommand(char *command, char *argv[], char *path): This function attempts to execute the specified command by searching for its executable in the given path. If the command is found, it is executed using the execve system call.

executeAbsoluteCommand(char *command, char *argv[]):
The function is responsible for executing the specified command with the given arguments in an absolute manner, meaning it executes the command regardless of the current working directory or environment. It does not rely on the system's search path (PATH variable) to locate the command.

void executeCommandInPath(char *command, char *argv[], char *path)
the function is to execute the specified command with the given arguments by searching for the command in the provided search path. The search path typically consists of a list of directories separated by a delimiter (such as ":" on Unix-like systems).



prompt(char *shellName): This function prompts the user for input and executes the entered command. It displays the shell prompt, reads the command from the user, tokenizes it into individual arguments, and executes the command using executecommand(). It also handles built-in commands like "exit" and "env".



tokenizeCommand(char *cmd, char *argv[], int *argc): This function tokenizes a command string by splitting it into individual tokens based on whitespace delimiters. The tokens are stored in the argv array, and the number of tokens is stored in the argc variable.


Usage
Run the shell program:
./hsh


Once the shell is running, you can enter commands just like you would in a regular shell environment.

The program supports basic shell commands and system commands. Some examples of supported commands are:

ls: List files and directories.

pwd: Print current working directory.


echo: Display text.


exit: Exit the shell program.


To exit the shell program, type exit or press Ctrl + C.