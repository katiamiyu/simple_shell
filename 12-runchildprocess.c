#include "main_shell.h"
/**
 * _runchildprocess - run child process
 * @argv: arrauy of arguments
 * @str: programe string
 * Return: integer
 */
int _runchildprocess(char **argv, char *str)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		return (-1);
	}
	if (pid == 0)
	{
		_execmd(argv, str);
		perror(str);
		exit(1);
	}
	return (pid);
}
