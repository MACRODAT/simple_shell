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
	data.na = na;
	data.a = a;
	data.interactive = 1;

	command(&data);

	return (1);
}
