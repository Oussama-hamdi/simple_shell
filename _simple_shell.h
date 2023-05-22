#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

#define MAX_ARGS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* Function prototypes */
void prompt(void);
int is_exit_command(char *command);
int is_cd_command(char *command);
int execute_command(char **args);
int execute_cd_command(char **args);
void free_memory(char *line, char **args);

#endif /* _SIMPLE_SHELL_H */
