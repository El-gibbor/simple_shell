#include "main.h"

/**
 * _isdigit - checks if a character is a digit
 * @c: character to be checked.
 * Return: 1 if it is a digit, otherwise 0
 */
int _isdigit(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}
