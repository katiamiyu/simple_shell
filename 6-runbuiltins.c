#include "main_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _runbuiltins - executes builtin commands
 * @argv: array of input commands (parameters)
 * @str: main call args
 * Return: 1 (failed), otherwise runcommands
 */
int _runbuiltins(char **argv, char *str)
{
	int count;
	char *builtin_commands[] = { "exit", "cd" };

	int numofbuiltins = sizeof(builtin_commands) / sizeof(char *);

	int (*builtin_functions[])(char **) = { &_exit_shell, &_cd_shell };

	if (argv[0] == NULL)
		return (1);

	for (count = 0; count < numofbuiltins ; count++)
	{
		if (_strcmp(argv[0], builtin_commands[count]) == 0)
			return ((*builtin_functions[count])(argv));
	}

	return (_execmd(argv, str));
}
