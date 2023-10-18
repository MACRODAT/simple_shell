#include "shell.h"

/**
 * _built_hist - ger gerg
 * @info: gregSgingre
 *  Return: ger
 */
int _built_hist(shell_data_ *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - erg
 * @info: pergrg
 * @str: thger
 *
 * Return: Alrgewaerg
 */
int unset_alias(shell_data_ *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, _stat_with_lst(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - dfg
 * @info: pdfg
 * @str: ger
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(shell_data_ *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (_ll_end_app(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - dwe
 * @node: dwede
 *
 * Return: dwe
 */
int print_alias(_lst *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _built_alias - mdwe
 * @info: dwed
 *  Return: Always 0
 */
int _built_alias(shell_data_ *info)
{
	int i = 0;
	char *p = NULL;
	_lst *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(_stat_with_lst(info->alias, info->argv[i], '='));
	}

	return (0);
}
