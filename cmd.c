#include "shell.h"

/**
 * command - displays command prompt and waits for user
 * @data: diehoo
 * Return: result
*/
int command(shelldata_ *data)
{
	char *cd_all = NULL;

	size_t len = BUFFER_SIZE_READER;
	int res;

	do {
		if (data->interactive == 1)
		{
			_puts("$ ");
			_putchar(SPECIAL_CHAR);
		}
		res = _getline(&cd_all, &len, stdin);
		if (!cd_all || res < 0)
			break;
		if (_process_lines(data, cd_all) != 0)
		{
			/* error processing */
		}
	} while (data->interactive);
	return (0);
}
