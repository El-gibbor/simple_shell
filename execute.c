#include "main.h"

/**
 * execute_cmd - Executes the given command.
 * @args: Array of arguments.
 * @av: Array of pointers to CLI args.
 */
void execute_cmd(char **args, char *av[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
		error_exit("Error: ");

	if (child_pid == 0)
	{
		execve(args[0], av, environ);
		perror(av[0]);
		exit(EXIT_FAILURE);
	}

	if (wait(&status) == -1)
		error_exit("Error: ");
}

