#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	/**
	 * pid_t getpid(void);
	 * pid_t getppid(void);
	 * --------------------
	 *  getpid() - gets the process ID of an executing program,
	 *  randomly generated unique ID at each execution.
	 *
	 *  getppid() - gets the parent process ID of the current process(xcuting prog).
	 *  ID is constant because it Idetifies a given child process regardless of
	 *  how many times this prog xcutes, the PPID identifies that child with a unique ID
	 */

	pid_t thePid;
	pid_t thePPid;

	thePid = getpid();
	thePPid = getppid();
	printf("%u\n", thePid);
	printf("%u\n", thePPid);
	return (0);
}
