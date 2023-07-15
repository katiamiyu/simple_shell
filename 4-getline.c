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

ssize_t _getline(char **ptr_buff, size_t *ptr_size, FILE *input_stream)
{
	ssize_t buffer = *ptr_size;
	ssize_t len = 0;
	int ch;
	char *new_buffer;

	if (ptr_buff == NULL || ptr_size == NULL)
		return (-1);

	while ((ch = fgetc(input_stream)) != '\0')
	{
		if (len >= buffer - 1)
		{
			buffer *= 2;

			/* resizes the buffer by doubling it */
			/* if is the buffer is to small to hold entire line */
			new_buffer = realloc(*ptr_buff, buffer);
			if (new_buffer == NULL)
				return (-1);

			(*ptr_buff) = new_buffer;
			*ptr_size = buffer;
		}

		(*ptr_buff)[len++] = ch;

		if (ch == '\n')
			break;
	}

	(*ptr_buff)[len] = '\0';

	if (len == 0 && ch == '\0')
		return (-1);

	return (len);
}
