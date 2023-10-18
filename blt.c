#include "shell.h"

/**
 * _built_help - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _built_help(shell_data_ *info)
{
	char **wedfio_hel;

	wedfio_hel = info->argv;
	_puts("my help \n");
	if (0)
		_puts(*wedfio_hel);
	return (0);
}

/**
 * _exit_shell - Handle the exit command.
 * @info: The info struct.
 *
 * Return: -2 if exit was requested, 1 on error,
 * or -2 if no exit argument.
 */
int _exit_shell(shell_data_ *info)
{
	int _flag;

	if (info->argv[1])
	{
		_flag = _erratoi(info->argv[1]);
		if (_flag == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_err_func(info->argv[1]);
			_err_func_char('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _built_cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _built_cd(shell_data_ *info)
{
	char *s, *dir, buffer[1024];
	int _ch_file;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("error");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			_ch_file =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			_ch_file = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		_ch_file =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		_ch_file = chdir(info->argv[1]);
	if (_ch_file == -1)
	{
		print_error(info, "can't cd to ");
		_err_func(info->argv[1]), _err_func_char('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
