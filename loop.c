#include "shell.h"

/**
 * find_builtin - finds a builtin command
 * @sh_data: dfssdfsdf
 *
 * Return: fsd
 */
int find_builtin(shell_data_ *sh_data)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _exit_shell},
		{"env", _env_en},
		{"help", _built_help},
		{"hst", _built_hist},
		{"setenv", _env_push},
		{"unsetenv", _myunsetenv},
		{"cd", _built_cd},
		{"alias", _built_alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(sh_data->poss[0], builtintbl[i].type) == 0)
		{
			sh_data->_ln_cnt++;
			built_in_ret = builtintbl[i].func(sh_data);
			break;
		}
	return (built_in_ret);
}

/**
 * start_execut - fsd
 * @sh_data: tfsd
 *
 * Return: fsd
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
		if (execve(sh_data->path, sh_data->poss, get_environ(sh_data)) == -1)
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
