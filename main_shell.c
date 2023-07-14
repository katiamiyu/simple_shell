#include <stdio.h>

int main(void)
{
	char name[20];

	do {
		printf("$ ");
		scanf("%s", name);

		printf("command not available yet %s\n", name);
	} while (1);

	return (0);
}
