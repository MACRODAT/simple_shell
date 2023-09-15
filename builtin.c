#include "shell.h"

/**
 * _print_env - fct
 * @data: data
 * Return: result
*/
int _builtin_print_env(shelldata_ *data)
{
	_print_env(data);
}

/**
 * _builtin_exit - fct
 * @data: data
 * Return: result
*/
int _builtin_exit(shelldata_ *data)
{
	free_info(data, 1);
	exit(1);
}

/**
 * _builtin_help - fct
 * @data: data
 * Return: result
*/
int _builtin_help(shelldata_ *data)
{
	_puts("HELP FOR COMMAND LINE\nBASIC COMMAND LINE \
		FOR UNIX SYSTEMS\nHELP NOT YET IMPLEMENTED\n");
}

/**
 * _builtin_set - fct
 * @data: data
 * Return: result
*/
int _builtin_set(shelldata_ *data)
{
	if (data->tokensize > 2)
		_set_env(data, data->command_tokens[1], data->command_tokens[2]);
	else
	{
		_puts_and_flush_e("Unsufficient number of parameters\n");
	}
}

/**
 * _builtin_unset - fct
 * @data: data
 * Return: result
*/
int _builtin_unset(shelldata_ *data)
{
	if (data->tokensize > 1)
		_unset_env(data, data->command_tokens[1]);
	else
	{
		_puts_and_flush_e("Unsufficient number of parameters\n");
	}
}

/**
 * _builtin_cd - fct
 * @data: data
 * Return: result
*/
int _builtin_cd(shelldata_ *data)
{
	int ind = 0;
	char *s, *dir, b[2048];

	s = getcwd(b, 2048);
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
			chdir(data->command_tokens[1]);
			s = getcwd(b, 2048);
			if (data->curdir && (!data->olddir || _strcmp(data->curdir, b) != 0))
				data->olddir = _strdup(data->curdir);
			_strcpy(data->curdir, b);
		}
		
		puts(b);
	}
	else
	{
		chdir(data->home);
		s = getcwd(b, 2048);
		if (data->curdir && (!data->olddir || _strcmp(data->curdir, b) != 0))
			data->olddir = _strdup(data->curdir);
		_strcpy(data->curdir, b);
		puts(b);
	}
}

/**
 * _exec_builtin - determines if builtin
 * if so execute
 * else returns -404
 * @cd: command
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
			return (d->f)(data);
		}
		d++;
	}
	return (-404);
}