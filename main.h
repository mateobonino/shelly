#ifndef MAIN_H
#define MAIN_H

#define C_TERMINAL "\033[H\033[J"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

extern char **environ;
void print_prompt(void);
int _printenv(void);
char *_strcat(char *, char *);
char *sh_read(void);
char **parse_cmd(char *prompt);
char *check(char **commands);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int charlen(char *s);
void _puts(char *str);
char *cmd_verify(char **commands);
int checked(char **commands, char **av);
void run_cmd(char **args);
int prompt_check(char *prompt);
int exec_args(char **checked_args);
char *_getenv(const char *);
int charlen(char *);
char *str_concat(char *, char *);
void gatorr(char **, char *, char *, int);
void checkcd(char **);

#endif /*MAIN_H*/
