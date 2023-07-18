/**
* _strtok - Breaks a parsed null-termited string(str) into a nonempty tokens
* @str: param, string to be parsed
* @delim: Set of bytes that delimit the tokens in the string
* Return: A pointer to the next nonempty token or NULL if no more tokens
*/

#include "main_shell.h"

char *_strtok(char *restrict str, const char *restrict delim)
{
	#define YES 1
	#define NO 0
	static char *next_token;
	const char *sep;
	char *token;
	int found_sep = NO;

	if (str != NULL)
		next_token = str;

	if (next_token == NULL)
		return (NULL);

	token = next_token;
	while (*next_token != '\0')
	{
		for (sep = delim; *sep != '\0'; sep++)
		{
			if (*next_token == *delim)
			{
				found_sep = YES;
				break;
			}
		}
		if (found_sep)
		{
			*next_token = '\0';
			next_token++;
			break;
		}
		next_token++;
	}
	if (*token == '\0')
		return (NULL);
	return (token);
}
