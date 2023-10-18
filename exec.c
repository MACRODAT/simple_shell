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


/**
 * find_cmd - fsdsd
 * @sh_data: tsdf
 *
 * Return: sdf
 */
void find_cmd(shell_data_ *sh_data)
{
	char *path = NULL;
	int i, k;

	sh_data->path = sh_data->poss[0];
	if (sh_data->_fla_lns == 1)
	{
		sh_data->_fla_lns = 0;
		sh_data->_ln_cnt++;
	}
	for (i = 0, k = 0; sh_data->arg[i]; i++)
		if (!is_delim(sh_data->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = where_is(sh_data, _env_pull(sh_data, "PATH="), sh_data->poss[0]);
	if (path)
	{
		sh_data->path = path;
		start_execut(sh_data);
	}
	else
	{
		if ((isnterop(sh_data) || _env_pull(sh_data, "PATH=")
			|| sh_data->poss[0][0] == '/') && executable(sh_data, sh_data->poss[0]))
			start_execut(sh_data);
		else if (*(sh_data->arg) != '\n')
		{
			sh_data->status = 127;
			print_error(sh_data, "not found\n");
		}
	}
}
