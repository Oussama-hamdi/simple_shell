#include "_simple_shell.h"
#include <stdbool.h>
/**
 * main - main func
 * Return: int
 */
int main(void)
{
	size_t memory_size = 0;
	char *cmd_prompt = NULL;
	char *smaller_strings;

	while (true)
	{
		char *arg_vectorPtr[MAX_ARGS];
		int number_args_passed = 0;

		if (isatty(0))
			printf("($) ");
		if (getline(&cmd_prompt, &memory_size, stdin) == -1)
			break;
		cmd_prompt[strcspn(cmd_prompt, "\n")] = '\0';
		if (strcmp(cmd_prompt, "exit") == 0)
			break;
		smaller_strings = strtok(cmd_prompt, " ");
		while ((number_args_passed < MAX_ARGS - 1) && smaller_strings)
		{
			arg_vectorPtr[number_args_passed] = smaller_strings;
			number_args_passed++;
			smaller_strings = strtok(NULL, " ");
		}
		arg_vectorPtr[number_args_passed] = NULL;
		execute_command(arg_vectorPtr);
	}
	free(cmd_prompt);
	return (0);

}
