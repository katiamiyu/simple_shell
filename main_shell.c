/**
 * main - entry point of program
 * @argc: number of arguments
 * @argv: arguement vector
 * Return: 0 on sucsess
 */

#include "main_shell.h"


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{

	/* variables */
	char  *buffer = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t read;

	(void)argc;

	while (1)
	{
		printf("($) ");
		read = _getline(&buffer, &len, stdin);

		/* track eol condition */
		if (read == -1)
		{
			free(buffer);
			return (1);
		}
		/* tokenize input and load command */
		args = _tokenize(buffer);
		_runbuiltins(args, argv[0]);

		free(args);
		free(buffer);
	}

	return (0);
}
