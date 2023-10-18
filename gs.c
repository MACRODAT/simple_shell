#include "shell.h"

/**
 * _env_pull - gerfgw
 * @sh_data: stuff
 * @name: envfgh
 *
 * Return: wed
 */
char *_env_pull(shell_data_ *sh_data, const char *name)
{
	_lst *node = sh_data->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->nx;
	}
	return (NULL);
}