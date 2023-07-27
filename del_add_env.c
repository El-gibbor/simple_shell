#include "main.h"

/**
 * add_env_var - add an environment variable to the list.
 * @head: a pointer to a pointer to the first node of the list.
 * @var: a pointer to the name of a variable.
 * @value: a pointer to the value of a variable.
 * Return: a pointer to the new node added.
 */
envlist_t *add_env_var(envlist_t **head, const char *var, const char *value)
{
	envlist_t **tmp;
	envlist_t *new_var;

	new_var = malloc(sizeof(envlist_t));
	if (new_var == NULL)
		return (NULL);
	new_var->env_var = _strdup(var);
	new_var->value = _strdup(value);

	for (tmp = head; *tmp; tmp = &(**tmp).next_env_var)
		;
	*tmp = new_var;
	new_var->next_env_var = NULL;

	return (new_var);
}

/**
 * delete_env_var - deletes a variable from the list.
 * @head: a pointer to a pointer to the first node of the list.
 * @name: the name of the variable to be deleted.
 * Return: always 0.
 */
int delete_env_var(envlist_t **head, const char *name)
{
	envlist_t *tmp, *h;

	for (h = *head; h; tmp = h, h = h->next_env_var)
		if (!_strncmp(name, h->env_var, _strlen(name)))
			break;

	if (h != NULL)
	{
		tmp->next_env_var = h->next_env_var;
		free(h->env_var);
		free(h->value);
		free(h);
	}
	return (0);
}
