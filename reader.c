#include "shell.h"

/**
 * _getline - better
 *
 * Returns: line size or -1
*/
size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int sz = 0;

	if ((sz = __getline(lineptr, n, stream)) < 0)
	{
		free(lineptr);
		return (-1);
	}
	else
	{
		return (sz);
	}
}