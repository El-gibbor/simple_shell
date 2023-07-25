#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s: params
 * Return: something
 */
int _atoi(char *s)
{
	unsigned int count, size, m;
	int k = 1;
	int i, j;

	m = 1;
	for (count = 0, size = 0; s[count]; count++)
	{
		if ((size && s[count] < '0') || s[count] > '9')
			break;

		if (s[count] == '-')
			k *= -1;

		if (s[count] >= '0' && s[count] <= '9')
		{
			if (size > 0)
				m *= 10;
			size++;
		}
	}

	for (j = 0, i = count - size; i < (int) count; i++)
	{
		j += ((s[i] - '0') * m);
		m /= 10;
	}
	return (j * k);
}
