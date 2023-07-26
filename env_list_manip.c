#include "main.h"

/**
 * search_env_var - searches for a variable in a list.
 * @head: a pointer to the first node of the list.
 * @name: a pointer to the name of the variable to be searched for.
 * Return: 1 when found, else 0.
 */
int search_env_var(const envlist_t *head, const char *name)
{
	for (; head; head = head->next_env_var)
		if (!_strncmp(name, head->env_var, _strlen(name)))
			return (1);
	return (0);
}

/**
 * overwrite_env_var - changes the value of a variable.
 * @head: a pointer to the first node of the list.
 * @name: a pointer to the name of the variable.
 * @value: a pointer to the value to the new value.
 * Return: 0 on success, -1 on failure.
 */
int overwrite_env_var(envlist_t *head, const char *name, const char *value)
{
	for (; head; head = head->next_env_var)
		if (!_strncmp(name, head->env_var, _strlen(name)))
		{
			free(head->value);
			head->value = _strdup(value);
			if (head->value == NULL)
				return (-1);
		}
	return (0);
}

/**
 * print_env_list - prints a list of environment variables.
 * @h: a pointer to the first node.
 */
void print_env_list(const envlist_t *h)
{
	char *tmp, *buf;

	for (; h; h = h->next_env_var)
	{
		tmp = string_nconcat(h->env_var, "=", 1);
		buf = string_nconcat(tmp, h->value, _strlen(h->value));

		write(STDOUT_FILENO, buf, _strlen(buf));
		write(1, "\n", 1);

		free(tmp);
		free(buf);
	}
}

/**
 * free_env_list - frees a list of environment variables.
 * @h: a pointer to the first node.
 */
void free_env_list(envlist_t *h)
{
	envlist_t *tmp;

	tmp = NULL;
	for (; h;)
	{
		tmp = h;
		h = h->next_env_var;
		free(tmp->env_var);
		free(tmp->value);
		free(tmp);
	}
}
