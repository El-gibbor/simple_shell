#include "main.h"

/**
 * build_path - creates a list of path directories.
 * Return: a pointer to the first node of the list.
 */
path_t *build_path(void)
{
	path_t *head;
	char **tmp, **s;

	head = NULL;
	s = tokenize_str(_getenv("PATH"), ":");

	for (tmp = s; *tmp; tmp++)
		if (add_path_dir(&head, *tmp) == NULL)
		{
			; /* Error message */
		}
	free_grid(s);
	return (head);
}

/**
 * add_path_dir - adds a pathname to the list.
 * @head: a pointer to a pointer to the first node in the list.
 * @s: a pointer to the pathname to be added.
 * Return: a pointer to the new node created.
 */
path_t *add_path_dir(path_t **head, const char *s)
{
	path_t **tmp, *new_dir = NULL;

	new_dir = malloc(sizeof(path_t));
	if (new_dir == NULL)
		return (NULL);

	if (s == NULL)
		s = "";
	new_dir->dir = _strdup(s);

	for (tmp = head; *tmp; tmp = &(**tmp).next_dir)
		;
	*tmp = new_dir;
	new_dir->next_dir = NULL;

	return (new_dir);
}
