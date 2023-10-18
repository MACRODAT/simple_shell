#include "shell.h"

/**
 * main - entghe
 * @cd_count: adfg
 * @args: dfg
 *
 * Return: 0 on success, 1 on error
 */
int main(int cd_count, char **args)
{
	shell_data_ sh_data[] = { sh_data_INIT };
	int gfw = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (gfw)
		: "r" (gfw));
	if (cd_count == 2)
	{
		gfw = open(args[1], O_RDONLY);
		if (gfw == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_err_func(args[0]);
				_err_func(": 0: Can't open ");
				_err_func(args[1]);
				_err_func_char('\n');
				_err_func_char(_F_BUF);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		sh_data->readgfw = gfw;
	}
	fill_env(sh_data);
	hstory(sh_data);
	loop_func(sh_data, args);

	return (EXIT_SUCCESS);
}
