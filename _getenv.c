#include "main.h"

/**
 * _getenv - searches for an environment list variable.
 * @name: a pointer to the name of a variable.
 * Return: a pointer to the corresponding value string.
 * Or NULL if variable not found.
 */
char *_getenv(const char *name)
{
	size_t i;

	if (name == NULL)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(environ[i], name, _strlen(name)))
			return (environ[i] + (_strlen(name) + 1));
	}
	return (NULL);
}
