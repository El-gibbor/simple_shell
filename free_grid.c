#include "main.h"

/**
 * free_grid - frees a 2 dimensional array.
 * @arr: the array to be freed.
 */
void free_grid(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
