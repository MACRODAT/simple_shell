#include "shell.h"

/**
 * _builtin_print_env - fct
 * @data: data
 * Return: result
*/
int _builtin_print_env(shelldata_ *data)
{
	_print_env(data);
	return (0);
}

/**
 * _builtin_exit - fct
 * @data: data
 * Return: result
*/
int _builtin_exit(shelldata_ *data)
{
	int exit_status = 0;

	if (data->tokensize > 1)
	{
		exit_status = _atoi(data->command_tokens[1]);
	}
	free_info(data, 1);
	exit(exit_status);
	return (0);
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
	return (0);
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
	return (0);
}
