#include "shell.h"


/**
 * loop_func - fdsfsdfsdfsdf
 * @sh_data: fsdsdf
 * @av: fsdsdfssd
 *
 * Return: fsdfs
 */
int loop_func(shell_data_ *sh_data, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_sh_data(sh_data);
		if (isnterop(sh_data))
			_puts("$ ");
		_err_func_char(_F_BUF);
		r = get_input(sh_data);
		if (r != -1)
		{
			set_sh_data(sh_data, av);
			builtin_ret = find_builtin(sh_data);
			if (builtin_ret == -1)
				find_cmd(sh_data);
		}
		else if (isnterop(sh_data))
			_putchar('\n');
		free_sh_data(sh_data, 0);
	}
	write_hst(sh_data);
	free_sh_data(sh_data, 1);
	if (!isnterop(sh_data) && sh_data->status)
		exit(sh_data->status);
	if (builtin_ret == -2)
	{
		if (sh_data->err_num == -1)
			exit(sh_data->status);
		exit(sh_data->err_num);
	}
	return (builtin_ret);
}
