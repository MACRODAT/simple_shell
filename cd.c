#include "shell.h"

/**
 * _built_cd - changes the current directory of the process
 * @sh_data: stuff
 *          stuff
 *  Return: Always 0
 */
int _built_cd(shell_data_ *sh_data)
{
	char *s, *dir, buffer[1024];
	int _ch_file;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("error");
	if (!sh_data->argv[1])
	{
		dir = _getenv(sh_data, "HOME=");
		if (!dir)
			_ch_file =
				chdir((dir = _getenv(sh_data, "PWD=")) ? dir : "/");
		else
			_ch_file = chdir(dir);
	}
	else if (_strcmp(sh_data->argv[1], "-") == 0)
	{
		if (!_getenv(sh_data, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(sh_data, "OLDPWD=")), _putchar('\n');
		_ch_file =
			chdir((dir = _getenv(sh_data, "OLDPWD=")) ? dir : "/");
	}
	else
		_ch_file = chdir(sh_data->argv[1]);
	if (_ch_file == -1)
	{
		print_error(sh_data, "can't cd to ");
		_err_func(sh_data->argv[1]), _err_func_char('\n');
	}
	else
	{
		_setenv(sh_data, "OLDPWD", _getenv(sh_data, "PWD="));
		_setenv(sh_data, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
