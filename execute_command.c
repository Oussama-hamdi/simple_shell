#include "_simple_shell.h"
/**
 * execute_command - execute cmd
 * @args_vector_ptr: argv
 * Return: int
 */
int execute_command(char **args_vector_ptr)
{
	int process_id_status;
	pid_t process_id;

	if (!args_vector_ptr[0])
		return (1);
	if (is_exit_command(args_vector_ptr[0]))
		return (0);
	if (is_cd_command(args_vector_ptr[0]))
		return (execute_cd_command(args_vector_ptr));
	process_id = fork();
	if (process_id == 0)
	{
		if (execvp(args_vector_ptr[0], args_vector_ptr) == -1)
			perror("Error");
		exit(8);
	}
	else if (process_id < 0)
		perror("Fork Error");
	else
	{
		do {
			waitpid(process_id, &process_id_status, WUNTRACED);
		} while (!WIFSIGNALED(process_id_status) && !WIFEXITED(process_id_status));
	}
	return (1);
}
