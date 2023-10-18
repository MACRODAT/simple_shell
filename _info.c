#include "shell.h"

/**
 * clear_sh_data - initializes shell_data_ struct
 * @sh_data: struct address
 */
void clear_sh_data(shell_data_ *sh_data)
{
	sh_data->arg = NULL;
	sh_data->argv = NULL;
	sh_data->path = NULL;
	sh_data->argc = 0;
}

/**
 * set_sh_data - initializes shell_data_ struct
 * @sh_data: struct address
 * @av: argument vector
 */
void set_sh_data(shell_data_ *sh_data, char **av)
{
	int i = 0;

	sh_data->fname = av[0];
	if (sh_data->arg)
	{
		sh_data->argv = strtow(sh_data->arg, " \t");
		if (!sh_data->argv)
		{

			sh_data->argv = malloc(sizeof(char *) * 2);
			if (sh_data->argv)
			{
				sh_data->argv[0] = _strdup(sh_data->arg);
				sh_data->argv[1] = NULL;
			}
		}
		for (i = 0; sh_data->argv && sh_data->argv[i]; i++)
			;
		sh_data->argc = i;

		alias_rep(sh_data);
		_ll_sub(sh_data);
	}
}

/**
 * free_sh_data - frees shell_data_ struct fields
 * @sh_data: struct address
 * @all: true if freeing all fields
 */
void free_sh_data(shell_data_ *sh_data, int all)
{
	my_free_(sh_data->argv);
	sh_data->argv = NULL;
	sh_data->path = NULL;
	if (all)
	{
		if (!sh_data->cmd_buf)
			free(sh_data->arg);
		if (sh_data->env)
			free_list(&(sh_data->env));
		if (sh_data->hst)
			free_list(&(sh_data->hst));
		if (sh_data->alias)
			free_list(&(sh_data->alias));
		my_free_(sh_data->environ);
			sh_data->environ = NULL;
		fr_db((void **)sh_data->cmd_buf);
		if (sh_data->readfd > 2)
			close(sh_data->readfd);
		_putchar(_F_BUF);
	}
}
