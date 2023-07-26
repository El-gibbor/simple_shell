#include "main.h"

envlist_t *head;

/**
 * build_env - creates a linked list of environment variables.
 * Return: a pointer to the first node of the list.
 */
envlist_t *build_env(void)
{
	int i;
	char **tmp;

	head = NULL;
	for (i = 0; environ[i]; i++)
	{
		tmp = tokenize_str(environ[i], "=");
		if (add_env_var(&head, tmp[0], _getenv(tmp[0])) == NULL)
		{
			;/* Error Message */
		}
		free_grid(tmp);
	}
	return (head);
}


/**
 * _setenv - adds or changes an environment variable
 * @name: a pointer to a variable's name.
 * @value: a pointer to a variable's value.
 * @overwrite: overwrite status
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || !*name)
		return (-1);

	if (search_env_var(head, name))
	{
		if (overwrite != 0)
		return (overwrite_env_var(head, name, value));
	}
	else
		if (add_env_var(&head, name, value))
			return (0);
	return (-1);
}

/**
 * _unsetenv - deletes a variable name from the environment.
 * @name: a pointer to a variable's name.
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
	if (name == NULL || !*name || *_strchrnul(name, '='))
		return (-1);

	if (search_env_var(head, name))
		return (delete_env_var(&head, name));
	return (0);
}
