#include "shell.h"

/**
 * _set_env - _set_env environment
 * @data: program data
 * @var: program data
 * @val: program data
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
		}
		_handle_node_env(data, curnode);
		if (flag)
			break;
		curnode = curnode->n;
	}
	if (!flag)
	{
		curnode = data->env;
		_ll_add_end(&(data->env), 1, var, val);
	}
}

/**
 * _unset_env - _unset_env environment
 * @data: program data
 * @var: program data
*/
void _unset_env(shelldata_ *data, char *var)
{
	_ll *curnode, *tmp;
	int flag = 0;

	if (!var)
	{
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
		}
		_handle_node_env(data, curnode);
		if (flag)
			break;
		curnode = curnode->n;
	}
	if (!flag)
	{
		_puts_e("Not found environment variable ");
		_puts_e(var);
		_puts_and_flush_e("\n");
	}
}
