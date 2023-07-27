/**
 * _runInterMode - run interactive commands
 * @argv: arguement vector
 * Return: 0 on sucsess
 */

#include "main_shell.h"


int _runInterMode(char **argv)
{

	/* variables */
	char  *buffer = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("($) ");
		read = getline(&buffer, &len, stdin);

		/* track eol condition */
		if (read <= 0)
		{
			printf("\n:");
			free(buffer);
			break;
		}
		/* tokenize input and load command */
		if (read != EOF)
		{
			args = _tokenize(buffer);
			_runbuiltins(args, argv[0]);
			free(args);
		}
	}

	free(buffer);
	return (0);
}
