#include <stdio.h>
#include <stdlib.h>

/**
 * Concept page exercise
 * ---------------------
 * Write a program that prints "$ ", wait for the user
 * to enter a command, prints it on the next line.
 */
int main(void)
{
	/**
	 * ssize_t getline(char **lineptr, size_t n, FILE *stream)
	 * -------------------------------------------------------
	 * getline() reads an entire line from a stream(file, stdin, etc) and
	 * store the address of the buffer containing this line in lineptr.
	 * @size_t n - is the size of the buffer holding this line.
	 * @stream - pointer to where the line/inputs is read from
	 * Returns the number of line(text/inputs) read, null byte excluded. then
	 * on faiure or encountered EOF condition it returns -1.
	 */

	/*
	   size_t n = 15;
	   char *lineBuff = malloc(n);

	   printf("$ ");
	   getline(&lineBuff, &n, stdin);

	//line is null terminated and includes a newline char
	printf("%slength of buffer: %ld\n", lineBuff, n);
	free(lineBuff); //ensure sure to free memory
	*/

	/**
	 * getline() dynamically reallocates memory to the buffer if
	 * the uswer allocated memory wasn't enough.
	 * It also dynamically allocate enough memory to the line buffer when
	 * theres no user spefied malloc, and buffer IS ASSIGNED NULL.
	 *
	 * Note: buffer must be freed by user after execution/use
	 */
	size_t n;
	char *lineBuff = NULL; /*must be assigned NULL*/

	printf("$ ");
	for (;;)
	{
		if (getline(&lineBuff, &n, stdin) != -1)
			printf("%slength of buffer: %ld\n", lineBuff, n);
			printf("$ ");
	}
	//**line is null terminated and includes a newline char

	/*memory must be freed by user after use*/
	free(lineBuff);
	return (0);
}
