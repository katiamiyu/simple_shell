#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _strtok - split a string into tokens
 * @str: string to be split
 * @delim: delimeter characters
 * Return: a pointer to the first token in the string, or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *dup_str;
	char *result;

	if (!str)
		str = dup_str;

	if (!str)
		return (NULL);

	while (1)
	{
		if (check_delim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}
	result = str;
	while (1)
	{
		if (*str == '\0')
		{
			dup_str = str;
			return (result);
		}
		if (check_delim(*str, delim))
		{
			*str = '\0';
			dup_str = str + 1;
			return (result);
		}
		str++;
	}
}
/**
 * check_delim - check for delimination
 * @c: character to be checked
 * @delim: string of deliminators
 * Return: 1  (success) 0 (failed)
 */
unsigned int check_delim(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}
