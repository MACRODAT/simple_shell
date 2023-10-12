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
		_puts_and_flush("\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		return (sz);
	}
}