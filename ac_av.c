#include <stdio.h>

/**
 * concept page exercise
 * ----------------------
 * a program that prints all the arguments, without using ac
*/

int main(int ac, char **av)
{
	(void)ac;

	while (*av)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}
