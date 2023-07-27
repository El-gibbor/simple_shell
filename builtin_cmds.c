#include "main.h"

/**
 * exit_cmd - exits the program with a termination status.
 * @cmd: an array of commands.
 * Return: Doesn't return, it exits
 */
cmd_t exit_cmd(char **cmd, int *status)
{
	char error[1024] = "./hsh: 1: exit: Illegal number: ";
	int i;

	if (cmd[1] == NULL)
	{
		free_grid(cmd);
		exit(*status);
	}

	for (i = 0; cmd[1][i]; i++)
		if (!_isdigit(cmd[1][i]))
		{
			_strcat(error, cmd[1]);
			write(STDERR_FILENO, error, _strlen(error));
			write(STDERR_FILENO, "\n", 1);
			free_grid(cmd);
			exit(*status);
		}
	*status = _atoi(cmd[1]);
	free_grid(cmd);
	exit(*status);
}

/**
 * env_cmd - prints the environment list.
 * @cmd: an array of commands.
 * Return: always TRUE.
 */
cmd_t env_cmd(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
	*status = 0;
	return (FOUND);
}
