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

/**
 * strpbrk_no - locates the first occurrence in the string s
 * of any bytes in the string accept
 * @s: a string
 * @accept: a string
 * Return: the index of the byte in s that matches
 * one of the bytes in accept;
 */
size_t strpbrk_no(const char *s, char *accept)
{
	char *p;
	size_t pos;

	for (pos = 0; s[pos]; pos++)
	{
		for (p = accept; *p; p++)
			if (s[pos] == *p)
				return (pos);
	}
	return (pos);
}

