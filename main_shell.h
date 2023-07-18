#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

ssize_t _getline(char **ptr_buff, size_t *ptr_size, FILE *input_stream);
char *_strtok(char *restrict str, const char *restrict delim);

#endif
