#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @_ll_lst: address of pointer to _ll_lst node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
_lst *add_node(_lst **_ll_lst, const char *str, int num)
{
	_lst *new__ll_lst;

	if (!_ll_lst)
		return (NULL);
	new__ll_lst = malloc(sizeof(_lst));
	if (!new__ll_lst)
		return (NULL);
	_memset((void *)new__ll_lst, 0, sizeof(_lst));
	new__ll_lst->num = num;
	if (str)
	{
		new__ll_lst->str = _strdup(str);
		if (!new__ll_lst->str)
		{
			free(new__ll_lst);
			return (NULL);
		}
	}
	new__ll_lst->nx = *_ll_lst;
	*_ll_lst = new__ll_lst;
	return (new__ll_lst);
}

/**
 * print_list_str - prints only the str element of a _lst linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const _lst *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->nx;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @_ll_lst: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
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
 * free_list - frees all nodes of a list
 * @_ll_lst_ptr: address of pointer to _ll_lst node
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

/**
 * _ll_end_app - adds a node to the end of the list
 * @_ll_lst: address of pointer to _ll_lst node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
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
	_memset((void *)new_node, 0, sizeof(_lst));
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
