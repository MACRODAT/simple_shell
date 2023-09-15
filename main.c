#include "shell.h"

/**
 * main - handles the shell
 * @na: num args
 * @a: args
 *
 * Return: 0 or 1
*/
int main(int na, char **a)
{
	shelldata_ data;

	if (na < 1)
		return (-1);
	initData(&data, na, a);
	_getFileName(data.a[0], &data.filename);

	command(&data);
	free_info(&data, 1);

	return (1);
}
