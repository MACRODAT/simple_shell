#include "shell.h"

/**
 * initData - initialise the data
 *
 * Return: 1 if ok
*/
void initData(shelldata_ *data, int na, char **a)
{
	data->na = na;
	data->a = a;
	data->interactive = 0;
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		data->interactive = 1;
}
