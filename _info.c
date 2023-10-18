#include "shell.h"

/**
 * clear_info - initializes shell_data_ struct
 * @info: struct address
 */
void clear_info(shell_data_ *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - initializes shell_data_ struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(shell_data_ *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		alias_rep(info);
		_ll_sub(info);
	}
}

/**
 * free_info - frees shell_data_ struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(shell_data_ *info, int all)
{
	my_free_(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->hst)
			free_list(&(info->hst));
		if (info->alias)
			free_list(&(info->alias));
		my_free_(info->environ);
			info->environ = NULL;
		fr_db((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(_F_BUF);
	}
}
