#include "main.h"

/**
 * builtin_handler - handles built-in commands.
 * @args: an array of pointers to strings / commands.
 * Return: FOUND or NOT_FOUND
 */
cmd_t builtin_handler(char **args)
{
	struct builtin cmd_arr[] = {
		{"exit", exit_cmd},
		{"env", env_cmd},
		{NULL, NULL}	};
	size_t i;
	char *tmp;

	for (i = 0; cmd_arr[i].cmd; i++)
	{
		tmp = cmd_arr[i].cmd;
		if (!_strncmp(args[0], tmp, _strlen(args[0])))
			return (cmd_arr[i].f(args));
	}
	return (NOT_FOUND);
}
