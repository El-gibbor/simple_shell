#include "main.h"

/**
 * _strcpy - copies a string to a buffer
 * @dest: pointer to the buffer
 * @src: pointer to a string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int len = 0, a = 0;

	while (*(src + len) != '\0')
		len++;
	for (; a <= len; a++)
		dest[a] = *(src + a);
	return (dest);
}
