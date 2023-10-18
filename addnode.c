#include "shell.h"

/**
 * add_node - adwed
 * @_ll_lst: adddwe
 * @str: sdwewe
 * @num: nynrtj
 *
 * Return: swed
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
