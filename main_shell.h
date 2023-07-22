#ifndef MAIN_H
#define MAIN_H







ssize_t _getline(char **ptr_buff, size_t *ptr_size, FILE *input_stream);

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int _strcmp(char *str1, char *str2);
char **_tokenize(char *str);
int _exit_shell(char **argv);
int _cd_shell(char **argv);
int _execmd(char **argv, char *str);
char *_loadpath(char *command);
int _runbuiltins(char **argv, char *str);


#endif
