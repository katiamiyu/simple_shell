/**
 * _runBatchMode - run batch commands
 * @argv: arguement vector
 * Return: void
 */

#include "main_shell.h"


void _runBatchMode(char **argv)
{

	/* variables */
	char  *buffer = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&buffer, &len, stdin)) != -1)
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}
		args = _tokenize(buffer);
		_runbuiltins(args, argv[0]);
		free(args);
	}

	free(buffer);
}
