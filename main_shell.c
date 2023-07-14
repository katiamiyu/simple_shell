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

	read = getline(&buffer, &len, stdin);

	if (read == -1)
	{
		perror("Unsuccessful");
		free(buffer);
		return (1);
	}
	
	printf("Buffer: %s", buffer);
	printf("Number of char read exclude delim(\\n): %ld\n", read);
	free(buffer);
	return (0);
}
