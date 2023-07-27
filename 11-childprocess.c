#include "main_shell.h"
/**
 * _childprocess - function allow child process
 * @pid: process id
 * Return: returns child status
 */
int _childprocess(pid_t pid)
{
	int status;

	waitpid(pid, &status, 0);

	return (status);
}
