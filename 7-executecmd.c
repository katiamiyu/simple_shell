#include "main_shell.h"
/**
 * _execmd - execute the commands
 * @argv: array of commands (parameters)
 * @str: string of names
 * Return: 0 success
 */
int _execmd(char **argv, char *str)
{
	int status;
	char *token_path = NULL;

	if ((int) strcspn(argv[0], "/") == 0)
	{
		status = execve(argv[0], argv, NULL);
	}
	else if ((int) strcspn(argv[0], ".") == 0)
	{
		status = execve(argv[0], argv, NULL);
	}
	else
	{
		/* add path to command */
		token_path = _loadpath(argv[0]);
		if (token_path == NULL) /* Check if returned pointer is NULL */
		{
			fprintf(stderr, "%s: %s: command not found\n", str, argv[0]);
			fflush(stderr);
			exit(127);
		}
		status = execve(token_path, argv, NULL);
		free(token_path);
	}
	if (status == -1)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", str, errno, argv[0]);
			fflush(stderr);
			exit(127);
		}
		else
			perror("execve");
		exit(1);
	}
	return (status);
}
