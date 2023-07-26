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

char *_strdup(const char *str);
const char *_strchrnul(const char *s, int c);
char *string_nconcat(char *s1, char *s2, unsigned int n);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, const char *src);


int _atoi(char *s);
int _isdigit(char c);

ssize_t _getline(char **cmd_line, size_t *n, int fd);
char **tokenize_str(char *str, char *delim);
size_t words_count(const char *s, const char *delim);
void free_grid(char **arr);
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

/* ========== Environment =========== */
extern char **environ;
char *_getenv(const char *name);


struct builtin
{
	char *cmd;
	cmd_t (*f)(char **);
};
cmd_t exit_cmd(char **);
cmd_t builtin_handler(char **);
cmd_t env_cmd(char **);

#endif /* main.h */
