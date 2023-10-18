#include "shell.h"

/**
 * delete_node_at_index - deldwe
 * @_ll_lst: addresdwe
 * @index: inddwe
 *
 * Return: dwe
 */
int delete_node_at_index(_lst **_ll_lst, unsigned int index)
{
	_lst *node, *prev_node;
	unsigned int i = 0;

	if (!_ll_lst || !*_ll_lst)
		return (0);

	if (!index)
	{
		node = *_ll_lst;
		*_ll_lst = (*_ll_lst)->nx;
		free(node->str);
		free(node);
		return (1);
	}
	node = *_ll_lst;
	while (node)
	{
		if (i == index)
		{
			prev_node->nx = node->nx;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->nx;
	}
	return (0);
}

/**
 * _ll_end_app - addew
 * @_ll_lst: adfwe
 * @str: stfew
 * @num: nofwe
 *
 * Return: sfwe
 */
_lst *_ll_end_app(_lst **_ll_lst, const char *str, int num)
{
	_lst *new_node, *node;

	if (!_ll_lst)
		return (NULL);

	node = *_ll_lst;
	new_node = malloc(sizeof(_lst));
	if (!new_node)
		return (NULL);
	_sh_nen((void *)new_node, 0, sizeof(_lst));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->nx)
			node = node->nx;
		node->nx = new_node;
	}
	else
		*_ll_lst = new_node;
	return (new_node);
}
