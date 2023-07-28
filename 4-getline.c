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
	static char buff[BUFFER_SIZE];
	static size_t buff_position;
	static ssize_t bytes_read;

	ssize_t buff_size = *ptr_size,  len = 0;
	int ch;
	char *new_buffer = NULL;

	/* Checks buffer, allocates memory and handle error */
	check_getline_buffer(ptr_buff, buff_size);

	while ((ch = fgetc(input_stream)) != EOF)
	{
		if ((ssize_t) buff_position >= bytes_read)
		{
			buff_position = 0;
			buff_position = fread(buff, sizeof(char), BUFFER_SIZE,
					input_stream);
			if (bytes_read == 0)
				break;
		}
		/* Checks and resizes the buffer_size by doubling it */
		resize_getline_buffer(ptr_buff, len, new_buffer, buff_size);

		(*ptr_buff)[len++] = buff[buff_position++];
		if (buff[buff_position - 1] == '\n')
			break;
	}
	if (len == 0 && ch == EOF)
		return (-1);
	(*ptr_buff)[len] = '\0';
	*ptr_size = buff_size;
	return (len);
}


/**
 * check_getline_buffer - Checks the buffer size and allocate memory
 * if necessary.
 *
 * @ptr_buff: A pointer to a pointer to the buffer.
 * @buff_size: The current size of the buffer.
 *
 * Return: -1 if memory allocation fails, otherwise returns 0.
 */

ssize_t check_getline_buffer(char **ptr_buff, ssize_t buff_size)
{
	if (*ptr_buff == NULL)
	{
		buff_size = 128;
		*ptr_buff = malloc(buff_size * sizeof(char));
		if (*ptr_buff == NULL)
			return (-1);
	}
	return (0);
}


/**
 * resize_getline_buffer - Resize the buffer if necessary.
 *
 * @ptr_buff: A pointer to a pointer to the buffer.
 * @len: The current length of the buffer.
 * @buff_size: The current size of the buffer.
 *
 * @Returns: 0 if the buffer was resized successfully, 1 otherwise.
 */

ssize_t resize_getline_buffer(char **ptr_buff, ssize_t len,
		char *new_buffer, ssize_t buff_size)
{
	/* Check if buffer needs to be resized */
	if (len >= buff_size - 1)
	{
		buff_size  *= 2;
		new_buffer = realloc(*ptr_buff, buff_size);
		if (new_buffer == NULL)
		{
			free(*ptr_buff);
			return (1);
		}
		/* Update pointer to buffer to the new buffer */
		*ptr_buff = new_buffer;
	}

	return (0);
}
