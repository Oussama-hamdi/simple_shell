#include "_simple_shell.h"
/**
 * execute_cd_command - executes cmd
 * @args_vector_ptr: argv
 * Return: int
 */
int execute_cd_command(char **args_vector_ptr)
{
	if (!args_vector_ptr[1])
		fprintf(stderr, "cd: missing argument\n");
	else
	{
		if (chdir(args_vector_ptr[1]) != 0)
			perror("cd");
	}
	return (1);
}
