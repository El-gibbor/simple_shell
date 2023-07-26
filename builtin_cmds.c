#include "main.h"

/**
 * exit_cmd - exits the program with a termination status.
 */
cmd_t exit_cmd(char **cmd)
{
	char error[1024] = "./hsh: 1: exit: Illegal number: ";
	int i, status = 2;

	if (cmd[1] == NULL)
	{
		free_grid(cmd);
		exit(status);
	}

	for (i = 0; cmd[1][i]; i++)
		if (!_isdigit(cmd[1][i]))
		{
			_strcat(error, cmd[1]);
			write(STDERR_FILENO, error, _strlen(error));
			write(STDERR_FILENO, "\n", 1);
			free_grid(cmd);
			exit(status);
		}
	status = _atoi(cmd[1]);
	free_grid(cmd);
	exit(0);
}

/**
 * env_cmd - prints the environment list.
 * @cmd: an array of commands.
 * Return: always TRUE.
 */
cmd_t env_cmd(char **cmd)
{
	envlist_t *head;

	(void) cmd;
	head = build_env();
	print_env_list(head);
	free_env_list(head);

	return (FOUND);
}
