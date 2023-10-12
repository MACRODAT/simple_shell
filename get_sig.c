#include "shell.h"

/**
 * get_sigint - CC
 * @sig: signal hand
 */
void get_sigint(int sig)
{
	(void)sig;
	_puts_and_flush("\n");
	exit(1);
}
