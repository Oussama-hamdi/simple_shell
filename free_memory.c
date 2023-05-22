#include "_simple_shell.h"

/**
* free_memory - Frees memory allocated for the line and arguments
* @line: Line to be freed
* @args: Arguments to be freed
*/

void free_memory(char *line, char **args)
{
	int i;

	free(line);
	if (args)
	{
		for (i = 0; args[i]; ++i)
		{
			free(args[i]);
		}
	free(args);
	}
}
