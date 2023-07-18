#include "main.h"

/**
 * _strlen - calculates the length of a string
 * @s:  pointer to the string
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	for (; *s != '\0'; i++)
		s++;
	return (i);
}
