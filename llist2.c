#include "shell.h"

/**
 * _ll_free - frees ll
 * @s: ll
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
 * _ll_delete2 - deletes ll node
 * @s: ll
 * Return: result
 */
_ll *_ll_delete2(_ll *s)
{
	_ll *tmp = NULL;

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

/**
 * _ll_delete - deletes ll node
 * @s: ll
 * Return: result
 */
_ll *_ll_delete(_ll *s)
{
	_ll *tmp = NULL;

	if (!s)
		return (NULL);
	if (s->n)
	{
		return (_ll_delete2(s));
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
