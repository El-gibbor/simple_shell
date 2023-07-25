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


/*========== functions for string manipulation ===========*/
size_t strpbrk_no(const char *s, char *accept);
size_t _strspn(const char *s, char *accept);
size_t _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, unsigned int n);
ssize_t _getline(char **cmd_line, size_t *n, int fd);

char *_strdup(const char *str);
const char *_strchrnul(const char *s, int c);
char *string_nconcat(char *s1, char *s2, unsigned int n);
char *_strncpy(char *dest, char *src, int n);


/* ========== PATH Directories ========== */

/**
 * struct path - a list of directories in the PATH.
 * @dir: a pointer to a pathname.
 * @next_dir: a pointer to the next pathname in the list.
 */
typedef struct path
{
	char *dir;
	struct path *next_dir;
} path_t;

path_t *build_path(void);
path_t *add_path_dir(path_t **head, const char *s);
void print_path_list(const path_t *h);
void free_path_list(path_t *h);
#endif /* main.h */
