#include "shell.h"

/**
 * print_list - prnts elements
 * @h: ptr
 *
 * Return: sz
 */
size_t print_list(const _lst *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(_numb_base_10(h->num, 10, 0));
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
 * list_len - few
 * @h: uoefv
 *
 * Return: hve
 */
size_t list_len(const _lst *h)
{
	size_t ind = 0;

	while (h)
	{
		h = h->nx;
		ind++;
	}
	return (ind);
}
