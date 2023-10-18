#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @sh_data: stuff
 *          stuff
 * Return: Always 0
 */
char **get_environ(shell_data_ *sh_data)
{
	if (!sh_data->environ || sh_data->env_changed)
	{
		sh_data->environ = _lsto_strings(sh_data->env);
		sh_data->env_changed = 0;
	}

	return (sh_data->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @sh_data: stuff
 *        stuff
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(shell_data_ *sh_data, char *var)
{
	_lst *node = sh_data->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			sh_data->env_changed = delete_node_at_index(&(sh_data->env), i);
			i = 0;
			node = sh_data->env;
			continue;
		}
		node = node->nx;
		i++;
	}
	return (sh_data->env_changed);
}

/**
 * _env_pshj - Initialize a new environment variable,
 *             or modify an existing one
 * @sh_data: stuff
 *        stuff
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _env_pshj(shell_data_ *sh_data, char *var, char *value)
{
	char *buf = NULL;
	_lst *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = sh_data->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			sh_data->env_changed = 1;
			return (0);
		}
		node = node->nx;
	}
	_ll_end_app(&(sh_data->env), buf, 0);
	free(buf);
	sh_data->env_changed = 1;
	return (0);
}
