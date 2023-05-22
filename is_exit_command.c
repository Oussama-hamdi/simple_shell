#include "_simple_shell.h"

/**
 * is_exit_command - Checks if the given command is (exit) command
 * @command: Command to check
 * Return: 1 if is (exit) else 0
 */

int is_exit_command(char *command)
{
	return (strcmp(command, "exit") == 0);
}

