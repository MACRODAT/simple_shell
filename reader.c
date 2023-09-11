#include "shell.h"

/**
 * _getline - better
 *
 * Returns: line size or -1
*/
size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int i = 0;
	size_t sz = 0;

	if ((sz = __getline(lineptr, n, stream)) == -1)
	{
		free(lineptr);
		return (-1);
	}
	else
	{
		// (*lineptr)[sz - 1] = 0;
		return (sz);
	}
}