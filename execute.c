#include "main.h"

/**
 * execute_cmd - executes command by calling execve in a child process
 * @args: an array of pointers to strings / commands.
 * @cmd_stat: command status, whether found or not.
 */
void execute_cmd(char **args, cmd_t cmd_stat)
{
	pid_t child_pid;
	int status;

	if (cmd_stat == NOT_FOUND)
	{
		execve(args[0], args, environ);
		perror(args[0]);
		return;
	}

	child_pid = fork();
	switch (child_pid)
	{
		case -1:
			error_exit("fork");
			break;
		case 0:
			execve(args[0], args, environ);
			break;
		default:
			if (wait(&status) == -1)
				error_exit("wait");
			break;
	}
}
