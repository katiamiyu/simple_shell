/**
 * _runInterMode - run interactive commands
 * @argv: arguement vector
 * Return: void
 */

#include "main_shell.h"


void  _runInterMode(char **argv)
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
			free(buffer);
			break;
		}
		/* tokenize input and load command */
		if (read != EOF)
		{
			if (strcmp(buffer, "exit") == 0)
				break;

			args = _tokenize(buffer);
			_runbuiltins(args, argv[0]);
			free(args);
			args = NULL;
			free(buffer);
			buffer = NULL;
		}
	}
}
