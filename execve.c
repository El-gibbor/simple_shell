#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
* main - Entry point
*
* Return: 0 (Sucess)
*/
int main(int ac, char **av)
{
	printf("here is a process (main) pid: %d\n", getpid());
	fork();
	printf("here is a process (after fork)pid: %d, ppid: %d\n", getpid(), getppid());
	return (0);
}
