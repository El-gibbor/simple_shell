#include "main.h"
/**
 * main - Executes a Unix command-line interpreter.
 * @ac: Number of CLI args.
 * @av: Array of pointers to CLI args.
 * Return: 0.
 */
int main(__attribute__((unused)) int ac, char *av[])
{
	size_t size_line;
	pid_t child_pid;
	int status, i, interactive_mode = isatty(STDIN_FILENO);
	char *cmd_line = NULL, **args = NULL;

	for (;;)
	{
		if (interactive_mode)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (getline(&cmd_line, &size_line, stdin) == -1)
		{
			if (interactive_mode)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		cmd_line[_strlen(cmd_line) - 1] = '\0';

		args = malloc(sizeof(char *) * 2);
		if (!args)
			error_exit("Error: ");
		args[0] = malloc(_strlen(cmd_line) + 1);
		if (!args[0])
			error_exit("Error: ");

		_strcpy(args[0], cmd_line);
		args[1] = NULL;

		child_pid = fork();
		if (child_pid < 0)
			error_exit("Error: ");
		if (child_pid == 0)
		{
			execve(args[0], av, environ);
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
		if (wait(&status) == -1)
			error_exit("Error: ");
		for (i = 0; i < 2; i++)
			free(args[i]);
	}
	free(args);
	free(cmd_line);
	exit(EXIT_SUCCESS);
}
