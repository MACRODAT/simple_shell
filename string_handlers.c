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
 *_puts_and_flush - printer
 *@str: str
 *
 * Return: 0
 */
void _puts_and_flush(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
		_putchar(str[i++]);
	_putchar(SPECIAL_CHAR);
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

/**
 * _getFileName - get file name
 * @path: path
 * @file: filename
 */
void _getFileName(char *path, char **file)
{
	int i = 0, j = 0, j_ = 0;

	while (path[i])
	{
		if (path[i] == '\\' || path[i] == '/')
			j = i;
		i++;
	}
	*file = malloc(sizeof(char) * (i - j + 2));
	for (j_ = j + 1; j_ < i; j_++)
		(*file)[j_ - j - 1] = path[j_];
	(*file)[j_] = 0;
}
