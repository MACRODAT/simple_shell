#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const _lst *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->nx;
		i++;
	}
	return (i);
}

/**
 * _lsto_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **_lsto_strings(_lst *head)
{
	_lst *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->nx, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a _lst linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const _lst *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->nx;
		i++;
	}
	return (i);
}

/**
 * _stat_with_lst - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the nx character after prefix to match
 *
 * Return: match node or null
 */
_lst *_stat_with_lst(_lst *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->nx;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(_lst *head, _lst *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->nx;
		i++;
	}
	return (-1);
}
