#include "shell.h"

/**
 * __getline - Read a line from standard input.
 *
 * This function reads a line of text from the standard input stream and stores
 * it in the provided buffer (*lineptr). If the buffer is too small, it is
 * dynamically resized to accommodate the input. Memory allocation failures and
 * read errors are handled, and an error message is printed when necessary.
 *
 * @lineptr: A pointer to a character pointer where the line will be stored.
 * @n: A pointer to the size of the buffer or the desired buffer size.
 * @stream: The stream to read from (unused in this implementation).
 *
 * Return: On success, returns the number of characters read, excluding the
 *         null terminator; on failure, returns -1.
 */
size_t __getline(char **lineptr, size_t *n, FILE *stream)
{
	char c = -2, *b = (char *)malloc(sizeof(char) * *n), *tmp;
	size_t bf = *n, i = 0;

	UNUSED(stream);
	if (!b)
	{
		_puts_and_flush_e("error");
		return (-1);
	}
	if (read(STDIN_FILENO, &c, 1) <= 0)
	{
		free(b);
		return (-1);
	}
	while (c != '\n' && c != '\0')
	{
		if (c > 0)
		{
			if (i >= bf - 2)
			{
				bf *= 2;
				tmp = (char *)realloc(b, sizeof(char) * bf);
				if (!tmp)
				{
					free(b), _puts_and_flush_e("error");
					return (-1);
				}
				b = tmp;
			}
			b[i++] = c;
		}

		if (feof(stdin) || read(STDIN_FILENO, &c, 1) <= 0)
		{
			b[i++] = c;
			break;
		}
	}
	b[i] = '\0', *lineptr = b;
	return (i);
}
