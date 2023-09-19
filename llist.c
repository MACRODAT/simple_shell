#include "shell.h"

/**
 * _ll_add_end - adds a node at end
 * @list: the list
 * @n: number
 * @s: string
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
		_puts(lst->s ? lst->s : "(nil)");
		if (lst->s2){
			_puts(dup);
			_puts(lst->s2);
		}
		_puts("\n");
		lst = lst->n;
		i++;
	}
	return (i);
}

/**
 * _ll_free - frees ll
 * @lst: ll
 */
void _ll_free(_ll *s)
{
	_ll *lst = s, *tmp = NULL;

	while (lst)
	{
		tmp = lst;
		if (lst->s2)
			free(lst->s2);
		if (lst->s)
			free(lst->s);
		free(lst);
		lst = tmp->n;
	}
}

/**
 * _ll_delete - deletes ll node
 * @lst: ll
 * Return: result
 */
_ll *_ll_delete(_ll *s)
{
	_ll *tmp = NULL;

	if (!s)
		return (NULL);
	if (s->n)
	{
		if (s->p)
		{
			tmp = s->p;
			s->p->n = s->n;
			s->n->p = s->p;
			if (s->s)
				free(s->s);
			if (s->s2)
				free(s->s2);
			while (tmp->p)
				tmp = tmp->p;
			return (tmp);
		}
		else
		{
			tmp = s->n;
			s->n->p = NULL;
			if (s->s)
				free(s->s);
			if (s->s2)
				free(s->s2);
			return (tmp);
		}
	}
	else
	{
		if (s->p)
		{
			tmp = s->p;
			s->p->n = NULL;
			if (s->s)
				free(s->s);
			if (s->s2)
				free(s->s2);
			while (tmp->p)
				tmp = tmp->p;
			return (tmp);
		}
		else
			return (NULL);
	}
}
