#include "main.h"

/**
 * _strcat - appends one string to another
 * @dest: the receiving string
 * @src: the string to be appended to dest.
 * Return: a pointer to the resulting string.
 */
char *_strcat(char *dest, const char *src)
{
	int len = 0;

	while (*dest)
		dest++, len++;

	while (*src)
	{
		*dest = *src;
		len++, src++, dest++;
	}
	dest[len] = '\0';
	dest -= len;
	return (dest);
}

/**
 * _strncpy - copies a string
 * @dest: points to the receiving string
 * @src: points to the string to be copied
 * @n: the number of bytes to be copied
 * Return: a pointer to the resulting string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int len = 0;

	for (; len < n && *src; *dest = *src,
			len++, src++, dest++)
		;
	for (; len <= n; *dest = '\0', dest++, len++)
		;
	dest -= len;
	return (dest);
}
