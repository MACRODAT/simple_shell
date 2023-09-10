#include "shell.h"

/**
 * _getline - waits for the user to print a newline
 *
 * Returns: line or null
*/
char *_getline()
{
	char c = -2;
	char *b = (char *)malloc(sizeof(char) * BUFFER_SIZE_READER);
	char *tmp;
	int bf = BUFFER_SIZE_READER;
	int i = 0;

	if (!b)
		// TODO HANDLE ERR
		return (NULL);

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
					return (NULL);
				}
				b = tmp;
			}
			b[i++] = c;
		}

		if (read(STDIN_FILENO, &c, 1) == -1)
		{
			// TODO HANDLE ERR
			free(b);
			return (NULL);
		}
	}

	return (b);
}