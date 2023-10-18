#include "shell.h"

/**
 * print_error - err
 * @sh_data: param
 * @wed_err: str
 * Return: something
 */
void print_error(shell_data_ *sh_data, char *wed_err)
{
	_err_func(sh_data->fname);
	_err_func(": ");
	print_d(sh_data->_ln_cnt, STDERR_FILENO);
	_err_func(": ");
	_err_func(sh_data->poss[0]);
	_err_func(": ");
	_err_func(wed_err);
}
