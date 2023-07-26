#include "main.h"

/**
 * error_exit - handles error.
 * @s: error message.
 */
void error_exit(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}
