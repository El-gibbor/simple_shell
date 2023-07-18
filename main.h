#ifndef MAIN_H
#define MAIN_H

/************* HEADER FILES **************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/********** Function Signatures *********/
int _strlen(char *s);
extern char **environ;
char *_strcpy(char *dest, const char *src);
void execute_cmd(char **args, char *av[]);
void error_exit(const char *error);
char **prepare_args(char *cmd_line);

#endif
