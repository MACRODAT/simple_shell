#include "shell.h"

/**
 * __getline - waits for the user to print a newline
 *
 * Returns: line or null
*/
size_t __getline(char **lineptr, size_t *n, FILE *stream)
{
	char c = -2;
	char *b = (char *)malloc(sizeof(char) * *n);
	char *tmp;
	size_t bf = *n;
	size_t i = 0;

	UNUSED(stream);
	if (!b)
	{
		_puts_and_flush_e("error");		
		return (-1);
	}
	while (c != EOF && c != '\n' && c != '\0')
	{
		if (c > 0)
		{
			if (i >= bf - 1)
			{
				bf *= 2;
				tmp = (char *)realloc(b, sizeof(char) * bf);
				if (!tmp)
				{
					free(b);
					_puts_and_flush_e("error");
					return (-1);
				}
				b = tmp;
			}
			b[i++] = c;
		}

		if (read(STDIN_FILENO, &c, 1) == -1)
		{
			_puts_and_flush_e("error");
			free(b);
			return (-1);
		}
	}
	b[i] = '\0';
	*lineptr = b;
	return (i);
}