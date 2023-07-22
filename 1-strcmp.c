#include "main_shell.h"
/**
 * _strcmp - compare two strings
 * @str1: first string parameter
 * @str2: second string parameter
 * Return: integer value
 */
int _strcmp(char *str1, char *str2)
{
	int count = 0;

	while ((str1[count] != '\0') && (str2[count] != '\0'))
	{
		if (str1[count] != str2[count])
		{
			return (str1[count] - str2[count]);
		}
		count++;
	}
	return (0);
}
