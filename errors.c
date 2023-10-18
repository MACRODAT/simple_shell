#include "shell.h"

/**
 *_err_func - wfe
 * @str: fergg
 * Return: Noui
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
 * _err_func_char - fwefwe
 * @c: fewfwe
 * Return: efw
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
 *_sf_gfw_sq - wedcw
 * @str: wcd
 * @gfw: thwc
 *
 * Return: wcd
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
