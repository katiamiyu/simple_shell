#include "main_shell.h"
/**
 * main - entry point of program
 * @argc: argument counter
 * @argv: vector pointer
 * Return: Success (0), failed (1)
 */
int main(int argc, char **argv)
{
	if (!(argc < 2))
	{
		printf("Usage: %s\n", argv[0]);
		return (1);
	}
	if (isatty(STDIN_FILENO))
	{
		_runInterMode(argv);
	}
	else
	{
		_runBatchMode(argv);
	}
	return (0);
}
