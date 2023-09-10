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
			
			if (_execute_command(cd) != 0)	
			{
				_puts(cd);
				_puts(": Command not found");
				_putchar('\n');
				_putchar(SPECIAL_CHAR);
			}
			else{
				
			}
		}
	}
}