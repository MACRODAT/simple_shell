#include "shell.h"

/**
 * free_list - fredwe
 * @_ll_lst_ptr: adew
 *
 * Return: void
 */
void free_list(_lst **_ll_lst_ptr)
{
	_lst *node, *nx_node, *_ll_lst;

	if (!_ll_lst_ptr || !*_ll_lst_ptr)
		return;
	_ll_lst = *_ll_lst_ptr;
	node = _ll_lst;
	while (node)
	{
		nx_node = node->nx;
		free(node->str);
		free(node);
		node = nx_node;
	}
	*_ll_lst_ptr = NULL;
}
