#include "shell.h"

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
