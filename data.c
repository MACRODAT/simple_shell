#include "shell.h"

/**
 * initData - initialise the data
 *
 * Return: 1 if ok
*/
void initData(shelldata_ *data, int na, char **a)
{
	char b[2048];

	data->na = na;
	data->a = a;
	data->interactive = 0;
	data->curdir = getcwd(b, 1024);
	data->olddir = NULL;
	data->commandNumber = 0;
	data->cd = malloc(sizeof(char) * STANDART_BUFFER);
	data->filename_full = _strdup(a[0]);
	_getFileName(data->a[0], &data->filename);
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		data->interactive = 1;
	_ll_init(&(data->env), 1000, "TEST ENV", "TEST VAL");
	_populate_env(data);
	
}

/**
 * __free_str_str - fress str of str
 * @s: str
*/
void __free_str_str(char **s)
{
	char **a = s;

	if (!s)
		return;
	
	while (*a)
		free(*a++);
	free(s);
}

/**
 * _free_data - frees data
 * @data: data
 * @flag: exiting
 */
void free_info(shelldata_ *data, int flag)
{
	__free_str_str(data->command_tokens);
	if (data->cd)
		free(data->cd);
	if (flag)
	{
		__free_str_str(data->paths);
		free(data->filename);
		if (data->olddir)
			free(data->olddir);
		_ll_free(data->env);
		_putchar(SPECIAL_CHAR);
	}
}
