#include "shell.h"

/**
 *_puts - printer
 *@str: str
 *
 * Return: 0
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
		_putchar(str[i++]);
}

/**
 * _putchar - writing c
 * @c: cghr
 *	
 * Return: 1 or -1
 */
int _putchar(char c)
{
	static int i;
	static char buffer[BUFFER_SIZE];

	if (c == SPECIAL_CHAR || i >= buffer[BUFFER_SIZE])
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != SPECIAL_CHAR)
		buffer[i++] = c;
	return (1);
}
