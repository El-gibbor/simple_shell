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

typedef enum boolean
{
	FALSE,
	TRUE
} bool_t;

/* Command Status */
typedef enum cmd
{
	NOT_FOUND,
	FOUND
} cmd_t;


extern char **environ;

/*========== functions for string manipulation ===========*/
void free_grid(char **arr);
char *_getenv(const char *name);
size_t strpbrk_no(const char *s, char *accept);
size_t _strspn(const char *s, char *accept);
size_t _strlen(const char *s);
int _isdigit(char c);
int _strncmp(const char *s1, const char *s2, unsigned int n);
ssize_t _getline(char **cmd_line, size_t *n, int fd);
char *_strdup(const char *str);
const char *_strchrnul(const char *s, int c);
char *string_nconcat(char *s1, char *s2, unsigned int n);
char *_strncpy(char *dest, char *src, int n);
#endif /* main.h */
