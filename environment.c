#include "shell.h"

/**
 * _separate_key_val - creates key val
 * @s: str
 * @key: key
 * @val: val
 *
 * Return: 0
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
 * @node: node
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
			data->paths = _splitString(data->path_content_str,
				delimiters, &(data->paths_len));
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
