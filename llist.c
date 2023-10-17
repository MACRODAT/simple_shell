#include "shell.h"

/**
 * _ll_add_end - adds a node at end
 * @list: the list
 * @n: number
 * @s: string
 * @s2: string
 * Return: size
*/
_ll *_ll_add_end(_ll **list, int n, char *s, char *s2)
{
	_ll *beg = *list;
	_ll *node;
	size_t _len = 0;

	if (!list || !*list)
		return (0);
	while (beg->n)
	{
		beg = beg->n;
		_len++;
	}
	node = malloc(sizeof(_ll));
	if (!node)
		return (0);
	node->n = NULL;
	node->p = beg;
	node->i = n;
	if (s)
	{
		node->s = _strdup(s);
		if (!node->s)
		{
			free(node);
			return (0);
		}
	}
	if (s2)
	{
		node->s2 = _strdup(s2);
		if (!node->s2)
		{
			free(node);
			return (0);
		}
	}
	beg->n = node;
	return (node);
}

/**
 * _ll_add_beg - adds a node at beg
 * @list: the list
 * @n: number
 * @s: string
 * @s2: string
 * Return: ptr
*/
_ll *_ll_add_beg(_ll **list, int n, char *s, char *s2)
{
	_ll *node;

	if (!list || !*list)
		return (NULL);
	node = malloc(sizeof(_ll));
	if (!node)
		return (NULL);
	node->n = *list;
	node->p = NULL;
	if (s)
	{
		node->s = _strdup(s);
		if (!node->s)
		{
			free(node);
			return (NULL);
		}
	}
	if (s2)
	{
		node->s2 = _strdup(s2);
		if (!node->s2)
		{
			free(node);
			return (0);
		}
	}
	node->i = n;
	(*list)->p = node;
	*list = node;
	return (node);
}

/**
 * _ll_init - creates ll
 * @n: number
 * @s: string
 * @s2: string
 * @list: string
 * Return: ptr
*/
_ll *_ll_init(_ll **list, int n, char *s, char *s2)
{
	_ll *node;

	node = malloc(sizeof(_ll));
	if (!node)
		return (NULL);
	node->n = NULL;
	node->p = NULL;
	if (s)
	{
		node->s = _strdup(s);
		if (!node->s)
		{
			free(node);
			return (NULL);
		}
	}
	if (s2)
	{
		node->s2 = _strdup(s2);
		if (!node->s2)
		{
			free(node);
			return (0);
		}
	}
	node->i = n;
	*list = node;
	return (node);
}

/**
 * _ll_print - prints ll
 * @lst: ll
 * @sep: ll
 *
 * Return: size of list
 */
size_t _ll_print(const _ll *lst, const char *sep)
{
	size_t i = 0;
	char *dup;

	dup = _strdup(sep);
	while (lst)
	{
		if (lst->s && _strcmp(lst->s, "OLDPWD") != 0)
		{
			_puts(lst->s);
			if (lst->s2)
			{
				_puts(dup);
				_puts(lst->s2);
			}
			_puts("\n");
		}
		lst = lst->n;
		i++;
	}
	return (i);
}
