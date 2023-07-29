#include "main.h"

/**
 * execute_cmd - executes command by calling execve in a child process
 * @args: an array of pointers to strings / commands.
 * @cmd_stat: command status, whether found or not.
 */
void execute_cmd(char **args, cmd_t cmd_stat, int *status)
{
	pid_t child_pid;
	/* int wait_stat; */

	if (cmd_stat == NOT_FOUND)
	{
		*status = 127;
		return;
	}

	child_pid = fork();
	switch (child_pid)
	{
		case -1:
			*status = errno;
			break;
		case 0:
			execve(args[0], args, environ);
			exit(2);
		default:
			wait(status);
			if (WIFEXITED(*status))
				*status = WEXITSTATUS(*status);
			break;
	}
}
