#include "shell.h"


/**
 * _myunsetenv - wef
 * @sh_data: stuff
 *        stuff
 *  Return: Always 0
 */
int _myunsetenv(shell_data_ *sh_data)
{
	if (sh_data->argc == 1)
	{
		_err_func("Too few arguements.\n");
		return (1);
	}

	return (0);
}
