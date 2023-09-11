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

	if ((sz = getline(lineptr, n, stream)) == -1)
		return (-1);
	else
	{
		(*lineptr)[sz - 1] = 0;
		return (sz);
	}
}