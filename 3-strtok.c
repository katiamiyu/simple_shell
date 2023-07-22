#include "main_shell.h"
#define YES 1
/**
 * _strtok - seperate strings into tokens
 * @str: string parameter
 * @delim: delimeter char(s)
 * Return: pointer to first token of the string or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *dup_str;
	char *res;

	if (!str)
		str = dup_str;

	if (!str)
		return (NULL);

	while (YES)
	{
		if (_check_delim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}
	res = str;
	while (YES)
	{
		if (*str == '\0')
		{
			dup_str = str;
			return (res);
		}
		if (_check_delim(*str, delim))
		{
			*str = '\0';
			dup_str = str + 1;
			return (res);
		}
		str++;
	}
}
/**
 * _check_delim - check for delimination
 * @c: char parameter
 * @delim: string parameter
 * Return: (success) 1, (failed)0
 */
unsigned int _check_delim(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}
