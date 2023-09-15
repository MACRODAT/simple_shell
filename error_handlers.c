#include "shell.h"

/**
 *_puts_e - printer
 *@str: str
 *
 * Return: 0
 */
void _puts_e(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
		_putchar_e(str[i++]);
}

/**
 *_puts_and_flush_e - printer
 *@str: str
 *
 * Return: 0
 */
void _puts_and_flush_e(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
		_putchar_e(str[i++]);
	_putchar_e(SPECIAL_CHAR);
}

/**
 * _putchar_e - writing c
 * @c: cghr
 *	
 * Return: 1 or -1
 */
int _putchar_e(char c)
{
	static int i;
	static char buffer[BUFFER_SIZE];

	if (c == SPECIAL_CHAR || i >= buffer[BUFFER_SIZE])
	{
		write(2, buffer, i);
		i = 0;
	}
	if (c != SPECIAL_CHAR)
		buffer[i++] = c;
	return (1);
}
