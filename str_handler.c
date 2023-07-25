#include "main.h"

/**
 * _strncmp - compares two strings
 * @s1: points to the first string
 * @s2: points to the second string
 * @n: length of s1
 * Return: 1 if the strings are equal, else s1 - s2
 */
int _strncmp(const char *s1, const char *s2, unsigned int n)
{
	for (; *s1 == *s2; s1++, s2++)
	{
		if (!--n)
			break;
		if (!*s1)
			return (0);
	}
	return (*s1 - *s2);
}
