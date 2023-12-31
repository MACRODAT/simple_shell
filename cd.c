#include "shell.h"

/**
 * _built_cd - cfew
 * @sh_data: stuff
 *          stuff
 *  Return: Always 0
 */
int _built_cd(shell_data_ *sh_data)
{
	char *s, *dir, arr_stor[1024];
	int _ch_file;

	s = getcwd(arr_stor, 1024);
	if (!s)
		_puts("error");
	if (!sh_data->poss[1])
	{
		dir = _env_pull(sh_data, "HOME=");
		if (!dir)
			_ch_file =
				chdir((dir = _env_pull(sh_data, "PWD=")) ? dir : "/");
		else
			_ch_file = chdir(dir);
	}
	else if (_strcmp(sh_data->poss[1], "-") == 0)
	{
		if (!_env_pull(sh_data, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_env_pull(sh_data, "OLDPWD=")), _putchar('\n');
		_ch_file =
			chdir((dir = _env_pull(sh_data, "OLDPWD=")) ? dir : "/");
	}
	else
		_ch_file = chdir(sh_data->poss[1]);
	if (_ch_file == -1)
	{
		print_error(sh_data, "can't cd to ");
		_err_func(sh_data->poss[1]), _err_func_char('\n');
	}
	else
	{
		_env_pshj(sh_data, "OLDPWD", _env_pull(sh_data, "PWD="));
		_env_pshj(sh_data, "PWD", getcwd(arr_stor, 1024));
	}
	return (0);
}
