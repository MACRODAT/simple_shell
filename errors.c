#include "shell.h"

/**
 *_err_func - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _err_func(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_err_func_char(str[i]);
		i++;
	}
}

/**
 * _err_func_char - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _err_func_char(char c)
{
	static int i;
	static char buf[_WR_B];

	if (c == _F_BUF || i >= _WR_B)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != _F_BUF)
		buf[i++] = c;
	return (1);
}

/**
 * _putgfw - writes the character c to given gfw
 * @c: The character to print
 * @gfw: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putgfw(char c, int gfw)
{
	static int i;
	static char buf[_WR_B];

	if (c == _F_BUF || i >= _WR_B)
	{
		write(gfw, buf, i);
		i = 0;
	}
	if (c != _F_BUF)
		buf[i++] = c;
	return (1);
}

/**
 *_sf_gfw_sq - prints an input string
 * @str: the string to be printed
 * @gfw: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _sf_gfw_sq(char *str, int gfw)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putgfw(*str++, gfw);
	}
	return (i);
}
