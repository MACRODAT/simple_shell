#include "shell.h"

/**
 * _separate_key_val - creates key val
 * @s: str
 * @key: key
 * @val: val
 *
 * Returns: 0
*/
int _separate_key_val(char *s, char **key, char **val)
{
	int ind = 0, len = 0, j = 0, flag = 0;

	if (!s)
		return (-1);
	while (s[ind] != '=')
		ind++;
	*val = _strdup(s + ind + 1);
	*key = malloc(sizeof(char) * ind);
	if (!*key)
		return (-1);
	len = 0;
	while (len < ind)
	{
		if (s[len] != ' ' || flag == 1)
		{
			(*key)[j++] = s[len];
			flag = 1;
		}
		len++;
	}
	return (0);
}

/**
 * _populate_env - gets env data
 * @data: program data
*/
void _populate_env(shelldata_ *data)
{
	int i = 0, res = 0;
	_ll *node;
	char *key = NULL, *val = NULL;

	while (environ[i])
	{
		res = _separate_key_val(environ[i], &key, &val);
		if (res == 0)
		{
			node = _ll_add_end(&(data->env), -1, key, val);
			_handle_node_env(data, node);
		}
		i++;
	}
	data->env_size = i;
}

/**
 * _handle_node_env - handles env
 * @data: data
 * @s: env
 * @node: node
 * @i: index
*/
void _handle_node_env(shelldata_ *data, _ll *node)
{
	char *delimiters;

	if (_strcmp(node->s, "PATH") == 0)
	{
		/* PATH ENV */
		data->path_content_str = node->s2;
		data->path_node = node;
		if (data->path_node)
		{
			delimiters = ":";
			data->paths = _splitString(data->path_content_str, delimiters, &(data->paths_len));
		}
	}
	else if (_strcmp(node->s, "HOME") == 0)
	{
		/* HOME ENV */
		data->home = node->s2;
	}
}

/**
 * _handle_node_env_del - handles deletion of env
 * @data: data
 * @var: node
*/
void _handle_node_env_del(shelldata_ *data, char *var)
{
	if (_strcmp(var, "PATH") == 0)
	{
		/* PATH ENV */
		data->path_content_str = "";
		data->path_node = NULL;
		data->paths = NULL;
	}
	else if (_strcmp(var, "HOME") == 0)
	{
		/* HOME ENV #TODO */
		data->home = "";
	}
}

/**
 * _print_env - prints environment
 * @data: program data
*/
void _print_env(shelldata_ *data)
{
	if (data && data->env && data->env->n)
		_ll_print(data->env->n, "=");
}

/**
 * _set_env - _set_env environment
 * @data: program data
*/
void _set_env(shelldata_ *data, char *var, char *val)
{
	_ll *curnode;
	int flag = 0;

	if (!var || !val)
	{
		/* _puts_and_flush_e("VARIABLES UNSET.\n"); */
		return;
	}
	curnode = data->env;
	while (curnode)
	{
		if (_strcmp(curnode->s, var) == 0)
		{
			/* env exists already */
			curnode->s2 = _strdup(val);
			flag = 1;
			/* _puts("Updated environment variable ");
			_puts(var);
			_putchar('\n'); */
		}
		/* update env vars */
		_handle_node_env(data, curnode);
		if (flag)
			break;
		curnode = curnode->n;
	}
	if (!flag)
	{
		/* set new env */
		curnode = data->env;
		_ll_add_end(&(data->env), 1, var, val);
		/* _puts("Created new environment variable ");
		_puts(var);
		_putchar('\n'); */
	}
}

/**
 * _unset_env - _unset_env environment
 * @data: program data
*/
void _unset_env(shelldata_ *data, char *var)
{
	_ll *curnode, *tmp;
	int flag = 0;

	if (!var)
	{
		/* _puts_and_flush_e("VARIABLES UNSET.\n"); */
		return;
	}
	curnode = data->env;
	while (curnode)
	{
		if (_strcmp(curnode->s, var) == 0)
		{
			/* env exists already */
			tmp = _ll_delete(curnode);
			if (tmp == NULL && data->env_size > 1)
			{
				_puts_and_flush_e("COULD NOT DELETE VARIABLE.\n");
				return;
			}
			data->env_size--;
			flag = 1;
			_handle_node_env_del(data, var);
			/* _puts("Deleted environment variable ");
			_puts(var);
			_putchar('\n'); */
		}
		/* update env vars */
		_handle_node_env(data, curnode);
		if (flag)
			break;
		curnode = curnode->n;
	}
	if (!flag)
	{
		_puts_and_flush_e("Not found environment variable");
		_puts_and_flush_e(var);
		_putchar_e('\n');
	}
}
