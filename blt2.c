#include "shell.h"

/**
 * _built_hist - ger gerg
 * @sh_data: gregSgingre
 *  Return: ger
 */
int _built_hist(shell_data_ *sh_data)
{
	print_list(sh_data->hst);
	return (0);
}

/**
 * unset_alias - erg
 * @sh_data: pergrg
 * @str: thger
 *
 * Return: Alrgewaerg
 */
int unset_alias(shell_data_ *sh_data, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(sh_data->alias),
		get_node_index(sh_data->alias, _stat_with_lst(sh_data->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - dfg
 * @sh_data: pdfg
 * @str: ger
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(shell_data_ *sh_data, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(sh_data, str));

	unset_alias(sh_data, str);
	return (_ll_end_app(&(sh_data->alias), str, 0) == NULL);
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
 * @sh_data: dwed
 *  Return: Always 0
 */
int _built_alias(shell_data_ *sh_data)
{
	int i = 0;
	char *p = NULL;
	_lst *node = NULL;

	if (sh_data->argc == 1)
	{
		node = sh_data->alias;
		while (node)
		{
			print_alias(node);
			node = node->nx;
		}
		return (0);
	}
	for (i = 1; sh_data->argv[i]; i++)
	{
		p = _strchr(sh_data->argv[i], '=');
		if (p)
			set_alias(sh_data, sh_data->argv[i]);
		else
			print_alias(_stat_with_lst(sh_data->alias, sh_data->argv[i], '='));
	}

	return (0);
}
