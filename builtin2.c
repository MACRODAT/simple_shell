#include "shell.h"

/**
 * _builtin_cd - fct
 * @data: data
 * Return: result
*/
int _builtin_cd(shelldata_ *data)
{
	char *s, b[2048];

	s = getcwd(b, 2048);
	UNUSED(s);
	if (data->tokensize > 1)
	{
		if (_strcmp(data->command_tokens[1], "-") == 0)
		{
			chdir(data->olddir);
			if (data->curdir)
				data->olddir = _strdup(data->curdir);
			s = getcwd(b, 2048);
			_strcpy(data->curdir, b);
		}
		else
		{
			if (chdir(data->command_tokens[1]) != 0)
			{
				char err[1000] = ": can't cd to ";

				_strcat(err, data->command_tokens[1]);
				_strcat(err, "\n");
				_print_error(err, data);
				return (-1);
			}
			s = getcwd(b, 2048);
			if (data->curdir && (!data->olddir || _strcmp(data->curdir, b) != 0))
				data->olddir = _strdup(data->curdir);
			_strcpy(data->curdir, b);
		}
	}
	else
	{
		chdir(data->home);
		s = getcwd(b, 2048);
		if (data->curdir && (!data->olddir || _strcmp(data->curdir, b) != 0))
			data->olddir = _strdup(data->curdir);
		_strcpy(data->curdir, b);
	}
	return (0);
}

/**
 * _builtin_help - fct
 * @data: data
 * Return: result
*/
int _builtin_help(shelldata_ *data)
{
	UNUSED(data);
	_puts("HELP FOR COMMAND LINE \nHELP NOT YET IMPLEMENTED\n");
	return (0);
}

/**
 * _exec_builtin - determines if builtin
 * if so execute
 * else returns -404
 * @cd: command
 * @data: command
 *
 * Return: number
*/
int _exec_builtin(char *cd, shelldata_ *data)
{
	_builtin_ builtins[] = {
		{"env", _builtin_print_env},
		{"exit", _builtin_exit},
		{"help", _builtin_help},
		{"cd", _builtin_cd},
		{"setenv", _builtin_set},
		{"unsetenv", _builtin_unset},
		{NULL, NULL}
	};
	_builtin_ *d = builtins;

	while (d->name)
	{
		if (strcmp(d->name, cd) == 0)
		{
			return ((d->f)(data));
		}
		d++;
	}
	return (-404);
}
