#include "main_shell.h"

/**
 * _exit_shell - terminates the shell
 * @argv: cammand instruction
 * Return: Exit on 0 (success)
 */
int _exit_shell(char **argv)
{
	(void)argv;

	exit(EXIT_SUCCESS);
}
/**
 * _cd_shell - switch from pwd
 * @argv: dir name to switch
 * Return: Exit on 1 (Success)
 */
int _cd_shell(char **argv)
{
	if (argv[1] == NULL)
	{
		fprintf(stderr, "err: wrong argument\n");
		return (1);
	}

	if (chdir(argv[1]) != 0)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, "Can't find dir: %s\n", argv[1]);
		}
		else
		{
			perror("Can't find dir");
		}
		return (1);
	}
	return (0);
}
