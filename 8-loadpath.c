#include "main_shell.h"
/**
 * _loadpath - get the path of a command
 * @token: strung of command
 * Return: char  NULL || fulladdress
 */
char *_loadpath(char *token)
{
	char *path, *path_copy, *path_token, *file_path;
	int token_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		token_len = strlen(token);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			dir_len = strlen(path_token);
			file_path = malloc(token_len + dir_len + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, token);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(token, &buffer) == 0)
			return (token);
		return (NULL);
	}
	return (NULL);
}
