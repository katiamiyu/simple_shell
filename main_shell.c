/**
 * main - entry point of program
 * @argc: number of arguments
 * @argv: arguement vector
 * Return: 0 on sucsess
 */

#include "main_shell.h"


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
		read = getline(&buffer, &len, stdin);

		/* track eol condition */
		if (read == -1)
		{
			free(buffer);
			break;
		}
		/* tokenize input and load command */
		if (read != EOF)
		{
			args = _tokenize(buffer);
			_runbuiltins(args, argv[0]);
		}
	}
	free(args);
	free(buffer);

	return (0);
}
