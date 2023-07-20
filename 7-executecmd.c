#include "main_shell.h"
/**
 * _execmd - execute the commands
 * @argv: array of commands (parameters)
 * @str: string of names
 * Return: 0 success
 */
int _execmd(char **argv, char *str)
{
	char *token = NULL;
	char *token_path = NULL;

	if (argv)
	{
		/* load command */
		token = argv[0];

		/* add path to command */
		token_path = _loadpath(token);

		if (execve(token_path, argv, NULL) == -1)
		{
			perror(str);
		}
	}
	return (0);
}
