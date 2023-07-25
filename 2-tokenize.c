#define TOKEN_BUFSIZE 100
#include "main_shell.h"
/**
 * _tokenize - break strings into tokens
 * @str: string parameter
 * Return: array of strings
 */
char **_tokenize(char *str)
{
	int x = 0;
	const char *delim = " \a\n\t\r";
	char *token;

	/* allocate memory space */
	char **tokens = malloc(sizeof(char *) * TOKEN_BUFSIZE);

	if (tokens == NULL)
	{
		fprintf(stderr, "error allocating memory\n");
		exit(1);
	}

	/* populate array with tokens */
	token = _strtok(str, delim);

	while (token)
	{
		tokens[x] = token;
		x++;

		token = _strtok(NULL, delim);
	}

	tokens[x] = NULL;

	return (tokens);
}
