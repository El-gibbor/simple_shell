#include "main.h"

/**
 * path_handler - handles the path.
 * @cmd: the command whose path is to be handled.
 * Return: a pointer to the path.
 */
char *path_handler(char *cmd)
{
	char *path, *s;
	path_t *head, *tmp = NULL;
	struct stat status;


	head = build_path();
	for (tmp = head; tmp; tmp = tmp->next_dir)
	{
		path = string_nconcat(tmp->dir, "/", 1);
		s = string_nconcat(path, cmd, _strlen(cmd));
		free(path);
		if (stat(s, &status) == 0)
		{
			free_path_list(head);
			return (s);
		}
		free(s);
	}
	free_path_list(head);
	return (NULL);
}

/**
 * ch_handler - handle quotes in a string.
 * @s: a pointer to a string.
 */
void ch_handler(char *s)
{
	int i, j;

	for (i = 0; s[i]; i++)
		if (s[i] == '\"' && s[i - 1] != '\\')
			for (j = i; s[j]; j++)
				s[j] = s[j + 1];

	for (i = 0; s[i]; i++)
		if (s[i] == '\\')
			for (j = i; s[j]; j++)
				s[j] = s[j + 1];
}
