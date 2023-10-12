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
	signal(2, get_sigint);
	initData(&data, na, a);
	if (na > 1)
	{
		if (_process_lines(&data, data.a[1]) < 0)
		{
			/* check for script file */
			if (_file_exists(data.a[1]))
			{
				data.interactive = 0;
				if (_exec_file(&data, a[1]) < 0)
				{
					_puts_e("Could not read file ");
					_puts_and_flush_e(a[1]);
					_puts_and_flush_e("\n");
				}
				return (1);
			}
		}
		else
		{
			return (1);
		}
	}
	command(&data);
	free_info(&data, 1);

	return (1);
}
