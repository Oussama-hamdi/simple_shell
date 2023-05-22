#include "_simple_shell.h"

/**
 * prompt - Displays the shell prompt
 */

void prompt(void)
{
	printf("$ "); /* Change the prompt as desired */
}

/**
 * read_line - Reads a line of input from user
 * Return: Input line as string
 */

char *read_line()
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("read_line");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}

