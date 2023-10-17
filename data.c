#include "shell.h"

/**
 * initData - initialise the data
 * @na: STUFF
 * @a: STUFF
 * @data: STUFF
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
	int i = 0;

	if (!s)
		return;

	while (a[i])
		free(a[i++]);
	if (s && *s != 0)
		free(s);
}

/**
 * free_info - frees data
 * @data: data
 * @flag: exiting
 */
void free_info(shelldata_ *data, int flag)
{
	if (data->cd)
		free(data->cd);
	data->cd = 0;
	__free_str_str(data->command_tokens);
	data->command_tokens = 0;

	if (flag)
	{
		__free_str_str(data->paths);
		data->paths = 0;
		free(data->filename);
		data->filename = 0;
		if (data->olddir)
			free(data->olddir);
		data->olddir = 0;
		_ll_free(data->env);
		data->env = 0;
		_putchar(SPECIAL_CHAR);
	}
}
