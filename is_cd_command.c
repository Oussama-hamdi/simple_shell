#include "_simple_shell.h"

/**
 * is_cd_command - checks command prompt
 * @command_promptPtr: pointer of cmd
 * Return: int
 */

int is_cd_command(char *command_promptPtr)
{
	return (strcmp(command_promptPtr, "cd") == 0);
}

