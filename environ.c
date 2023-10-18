#include "shell.h"

/**
 * _env_en - pdwedwe
 * @sh_data: stuff
 *          stuff
 * Return: Always 0
 */
int _env_en(shell_data_ *sh_data)
{
	print_list_str(sh_data->env);
	return (0);
}

/**
 * _env_push - wef
 * @sh_data: stuff
 *        stuff
 *  Return: Always 0
 */
int _env_push(shell_data_ *sh_data)
{
	if (sh_data->argc != 3)
	{
		_err_func("Incorrect number of arguements\n");
		return (1);
	}
	if (_env_pshj(sh_data, sh_data->argv[1], sh_data->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - wef
 * @sh_data: stuff
 *        stuff
 *  Return: Always 0
 */
int _myunsetenv(shell_data_ *sh_data)
{
	int i;

	if (sh_data->argc == 1)
	{
		_err_func("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= sh_data->argc; i++)
		_unsetenv(sh_data, sh_data->argv[i]);

	return (0);
}

/**
 * fill_env - populates env linked list
 * @sh_data: stuff
 *          stuff
 * Return: Always 0
 */
int fill_env(shell_data_ *sh_data)
{
	_lst *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		_ll_end_app(&node, environ[i], 0);
	sh_data->env = node;
	return (0);
}
