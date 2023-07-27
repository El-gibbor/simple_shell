#include "main.h"

/**
 * main - program starts here.
 * @ac: argument count
 * @av: argument vector
 * Return: always 0.
 */
int main(int ac, char **av)
{
	char *prompt = "#cisfun~$ ";
	int interactive_mode = isatty(STDIN_FILENO);

	(void) av;
	(void) ac;

	while (1)
	{
		if (interactive_mode)
			write(1, prompt, _strlen(prompt));
		if (get_cmd(interactive_mode))
			break;
	}
	return (0);
}

/**
 * get_cmd - gets a command from stdout and performs action
 * @interactive_mode: return of isatty(STDIN_FILENO).
 * Return: 0 on success, 1 on error.
 */
int get_cmd(int interactive_mode)
{
	char *path, **args, *cmd_line = NULL;
	size_t size = 0;
	struct stat statbuf;
	cmd_t cmd_stat = FOUND;		/* Command status */
	/* getting command from the commandline */
	if (_getline(&cmd_line, &size, STDIN_FILENO) == -1)
	{
		if (interactive_mode)
			write(1, "\n", 1);
		free(cmd_line);
		return (1);
	}
	ch_handler(cmd_line);
	args = tokenize_str(cmd_line, " \n\t");		/* tokenize the command */
	free(cmd_line);
	if (args[0] == NULL)
	{
		free(args);
		return (0);
	}
	/*	if (builtin_handler(args) == TRUE) */
	/*{*/
	/*	free_grid(args);*/
	/*	return (0);*/
	/*} */
	/* Search for command in current path and in PATH */
	if (stat(args[0], &statbuf) != 0)
	{
		cmd_stat = NOT_FOUND;
		path = path_handler(args[0]);
		if (path != NULL)
		{
			free(args[0]);
			args[0] = path;
			cmd_stat = FOUND;
		}
	}
	execute_cmd(args, cmd_stat);
	free_grid(args);
	return (0);
}
