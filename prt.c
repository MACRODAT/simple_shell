#include "shell.h"

/**
 * print_list_str - prindw
 * @dass: pointdwe
 *
 * Return: siwed
 */
size_t print_list_str(const _lst *dass)
{
	size_t i = 0;

	while (dass)
	{
		_puts(dass->str ? dass->str : "(nil)");
		_puts("\n");
		dass = dass->nx;
		i++;
	}
	return (i);
}
