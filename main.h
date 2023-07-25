#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFSIZE 1024

/* Command Status */
typedef enum cmd
{
	NOT_FOUND,
	FOUND
} cmd_t;


/*========== functions for string manipulation ===========*/
size_t strpbrk_no(const char *s, char *accept);
size_t _strspn(const char *s, char *accept);
size_t _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, unsigned int n);

#endif /* main.h */
