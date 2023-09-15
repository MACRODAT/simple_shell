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
	int i = 0;

	if (!b)
		// TODO HANDLE ERR
		return (-1);

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
					free(b); //TODO ERR
					return (-1);
				}
				b = tmp;
			}
			b[i++] = c;
		}

		if (read(STDIN_FILENO, &c, 1) == -1)
		{
			// TODO HANDLE ERR
			free(b);
			return (-1);
		}
	}
	b[i] = '\0';
	*lineptr = b;
	return (i);
}