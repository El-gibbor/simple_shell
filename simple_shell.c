#include "main.h"

/**
 * main - xcutes a unix cmdline interpreter
 * @ac: Number of CLI args.
 * @av: array of pointers to CLI args
 * Return: 0
 */
int main(int ac, char *av[])
{
	char *cmd_line = NULL, **args = NULL;
	size_t size_line;
	pid_t child_pid;
	int status, i;

	(void) ac;
	for (; isatty(STDIN_FILENO);)
	{
		write(1, "#cisfun$ ", 9);

		if (getline(&cmd_line, &size_line, stdin) < 0)
			break;
		if (*cmd_line == EOF)
			exit(0);

		cmd_line[_strlen(cmd_line) - 1] = '\0';

		args = malloc(sizeof(char *) * 2);
		if (!args)
			perror("Error: ");
		args[0] = malloc(_strlen(cmd_line) + 1);
		if (!args[0])
			perror("Error: ");
	
		_strcpy(args[0], cmd_line);
		args[1] = NULL;

		child_pid = fork();
		if (child_pid < 0)
			perror("Error: ");
		if (child_pid == 0)
		{
			execve(args[0], av, environ);
			perror(av[0]);
			exit(98);
		}
		wait(&status);
		for (i = 0; i < 2; i++)
			free(args[i]);
	}
	free(args);
	free(cmd_line);
	exit(0);
}
