#include "shell.h"

/**
 * main - entry point
 * @cd_count: arg count
 * @args: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int cd_count, char **args)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (cd_count == 2)
	{
		fd = open(args[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_err_func(args[0]);
				_err_func(": 0: Can't open ");
				_err_func(args[1]);
				_err_func_char('\n');
				_err_func_char(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	fill_env(info);
	hstory(info);
	loop_func(info, args);
	return (EXIT_SUCCESS);
}
