/**
 * _getline -  Reads a line of input from stdin and stores it in a buffer.
 *
 * @ptr_buff: Pointer to the buffer where the line is stored.
 * @ptr_size: Pointer to the size of the buffer.
 * @input_stream: Pointer to the input stream.
 *
 * Return: Number of characters read, excluding the terminating null byte,
 *         or -1 if an error occurs or end of line is reached.
 */

#include "main_shell.h"

ssize_t  _getline(char **ptr_buff, size_t *ptr_size, FILE *input_stream)
{
	ssize_t buff_size = *ptr_size,  len = 0;
	int ch;
	char *new_buffer;

	/* Checks buffer, allocates memory and handle error */
	if (*ptr_buff == NULL)
	{
		buff_size = 128;
		*ptr_buff = malloc(buff_size * sizeof(char));
		if (*ptr_buff == NULL)
			return (-1);
	}

	while ((ch = fgetc(input_stream)) != EOF)
	{
		/* Checks and resizes the buffer_size by doubling it */
		/* if it can't hold entire line, then reallocate memory */
		if (len >= buff_size - 1)
		{
			buff_size *= 2;
			new_buffer = realloc(*ptr_buff, buff_size);
			if (new_buffer == NULL)
			{
				free(*ptr_buff);
				return (-1);
			}
			*ptr_buff = new_buffer;
		}

		(*ptr_buff)[len++] = ch;
		if (ch == '\n')
			break;
	}
	if (len == 0 && ch == EOF)
		return (-1);
	(*ptr_buff)[len] = '\0';
	return (len);
}
