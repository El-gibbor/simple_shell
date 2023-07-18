#include "main.h"

/**
 * error_exit - prints and error and exit
 * @error: error to be printed with errono
*/
void error_exit(const char *error)
{
    perror(error);
    exit(EXIT_FAILURE);
}