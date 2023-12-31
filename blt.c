#include "shell.h"

/**
 * _built_help - changes the low_fd_nw directory of the process
 * @sh_data: stuff
 *          stuff
 *  Return: Always 0
 */
int _built_help(shell_data_ *sh_data)
{
	char **wedfio_hel;

	wedfio_hel = sh_data->poss;
	_puts("my help \n");
	if (0)
		_puts(*wedfio_hel);
	return (0);
}

/**
 * _exit_shell - Handle the exit command.
 * @sh_data: The sh_data struct.
 *
 * Return: -2 if exit was requested, 1 on error,
 * or -2 if no exit argument.
 */
int _exit_shell(shell_data_ *sh_data)
{
	int _flag;

	if (sh_data->poss[1])
	{
		_flag = _erratoi(sh_data->poss[1]);
		if (_flag == -1)
		{
			sh_data->status = 2;
			print_error(sh_data, "Illegal number: ");
			_err_func(sh_data->poss[1]);
			_err_func_char('\n');
			return (1);
		}
		sh_data->err_num = _erratoi(sh_data->poss[1]);
		return (-2);
	}
	sh_data->err_num = -1;
	return (-2);
}
