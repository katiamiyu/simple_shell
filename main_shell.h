#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int _strcmp(char *str1, char *str2);
char **_tokenize(char *str);
int exit_shell(char **argv);
int cd_shell(char **argv);
int _execmd(char **argv, char *str);
char *_loadpath(char *command);
int _runbuiltins(char **argv, char *str);

#endif
