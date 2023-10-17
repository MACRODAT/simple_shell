#include "shell.h"

/**
 *_puts_e - printer
 *@str: str
 *
 * Return: 0
 */
void _puts_e(const char *str)
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
void _puts_and_flush_e(const char *str)
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
int _putchar_e(const char c)
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

/**
 * _print_error - writing c
 * @c: cghr
 * @data: cghr
 *
 * Return: 1 or -1
 */
int _print_error(const char *c, shelldata_ *data)
{
	char *tmp;

	_putchar_e('.');
	_putchar_e('/');
	_puts_e(data->filename);
	_putchar_e(':');
	_putchar_e(' ');
	tmp = _strfromint(data->commandNumber);
	_puts_and_flush_e(tmp);
	_putchar_e(':');
	_putchar_e(' ');
	if (_starts_with(data->cd, "cd") != NULL)
		_puts_and_flush_e("cd");
	else
	{
		_puts_and_flush_e(data->cd);
	}
	_puts_and_flush_e(c);
	free(tmp);

	return (0);
}
