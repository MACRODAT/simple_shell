#include "shell.h"

/**
 * command - displays command prompt and waits for user
 *
 * Return: result
*/
int command(shelldata_ *data)
{
	char *cd = NULL;
	size_t len = BUFFER_SIZE_READER;
	int res;


	while (1)
	{
		if (data->interactive == 1)
		{
			_puts("#$# ");
			_putchar(SPECIAL_CHAR);

			res = _getline(&cd, &len, stdin);
			if (!cd || res < 0)
				break;
			
			if (_execute_command(cd) != 0)	
			{
				// _puts(cd);
				_putchar('.');
				_putchar('/');
				_puts(data->filename);
				_puts(": No such file or directory");
				_putchar('\n');
				_putchar(SPECIAL_CHAR);
			}
			else{
				// TODO error
				break;
			}
		}
		else
		{
			_puts_and_flush("non-interactive\n");
			break;
		}
	}
}