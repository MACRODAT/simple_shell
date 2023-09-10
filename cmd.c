#include "shell.h"

/**
 * command - displays command prompt and waits for user
 *
 * Return: result
*/
int command(shelldata_ *data)
{
	char *cd = NULL;


	while (1)
	{
		if (data->interactive)
		{
			_puts("#$# ");
			_putchar(SPECIAL_CHAR);

			cd = _getline();
			_puts(cd);
			_putchar('\n');
			_putchar(SPECIAL_CHAR);
		}
	}
}