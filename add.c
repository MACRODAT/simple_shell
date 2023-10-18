#include "shell.h"

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
