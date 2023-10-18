#include "shell.h"

/**
 * loop_func - main shell loop
 * @sh_data: the parameter & return sh_data struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int loop_func(shell_data_ *sh_data, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_sh_data(sh_data);
		if (interactive(sh_data))
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
		else if (interactive(sh_data))
			_putchar('\n');
		free_sh_data(sh_data, 0);
	}
	write_hst(sh_data);
	free_sh_data(sh_data, 1);
	if (!interactive(sh_data) && sh_data->status)
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
 * find_builtin - finds a builtin command
 * @sh_data: the parameter & return sh_data struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(shell_data_ *sh_data)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _exit_shell},
		{"env", _myenv},
		{"help", _built_help},
		{"hst", _built_hist},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _built_cd},
		{"alias", _built_alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(sh_data->argv[0], builtintbl[i].type) == 0)
		{
			sh_data->_ln_cnt++;
			built_in_ret = builtintbl[i].func(sh_data);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @sh_data: the parameter & return sh_data struct
 *
 * Return: void
 */
void find_cmd(shell_data_ *sh_data)
{
	char *path = NULL;
	int i, k;

	sh_data->path = sh_data->argv[0];
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

	path = where_is(sh_data, _getenv(sh_data, "PATH="), sh_data->argv[0]);
	if (path)
	{
		sh_data->path = path;
		start_execut(sh_data);
	}
	else
	{
		if ((interactive(sh_data) || _getenv(sh_data, "PATH=")
			|| sh_data->argv[0][0] == '/') && executable(sh_data, sh_data->argv[0]))
			start_execut(sh_data);
		else if (*(sh_data->arg) != '\n')
		{
			sh_data->status = 127;
			print_error(sh_data, "not found\n");
		}
	}
}

/**
 * start_execut - forks a an exec thread to run cmd
 * @sh_data: the parameter & return sh_data struct
 *
 * Return: void
 */
void start_execut(shell_data_ *sh_data)
{
	pid_t _pid_chi;

	_pid_chi = fork();
	if (_pid_chi == -1)
	{
		perror("Error:");
		return;
	}
	if (_pid_chi == 0)
	{
		if (execve(sh_data->path, sh_data->argv, get_environ(sh_data)) == -1)
		{
			free_sh_data(sh_data, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(sh_data->status));
		if (WIFEXITED(sh_data->status))
		{
			sh_data->status = WEXITSTATUS(sh_data->status);
			if (sh_data->status == 126)
				print_error(sh_data, "Permission denied\n");
		}
	}
}
