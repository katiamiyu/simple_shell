/**
 * main - entry point of program
 * Return: 0 on sucsess
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char  *buffer = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("($) ");
		read = getline(&buffer, &len, stdin);

		/* track eol condition */
		if (read == -1)
		{
			return (1);
		}

		printf("($) %s", buffer);
	}

	free(buffer);
	return (0);
}
