#include "main_shell.h"

int main(void)
{
	char str[128], *token;
	int n = 0;

	printf("Enter a string separated by white space: ");
	fgets(str, sizeof(str), stdin);

	token = _strtok(str, " ");

	while (token != NULL)
	{
		n++;
		printf("Token%d: %s\n", n, token);
		token = _strtok(NULL, " ");
	}
    return 0;
}
