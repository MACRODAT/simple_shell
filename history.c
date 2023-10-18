#include "shell.h"

/**
 * _file_hst_loc - erg
 * @sh_data: ger
 *
 * Return: ger
 */

char *_file_hst_loc(shell_data_ *sh_data)
{
	char *_ll_pl, *dir;

	dir = _env_pull(sh_data, "HOME=");
	if (!dir)
		return (NULL);
	_ll_pl = malloc(sizeof(char) * (_strlen(dir) + _strlen(FILE_HST) + 2));
	if (!_ll_pl)
		return (NULL);
	_ll_pl[0] = 0;
	_strcpy(_ll_pl, dir);
	_strcat(_ll_pl, "/");
	_strcat(_ll_pl, FILE_HST);
	return (_ll_pl);
}

/**
 * write_hst - ewfwe
 * @sh_data: apr
 *
 * Return: 1
 */
int write_hst(shell_data_ *sh_data)
{
	ssize_t gfw;
	char *filename = _file_hst_loc(sh_data);
	_lst *node = NULL;

	if (!filename)
		return (-1);

	gfw = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (gfw == -1)
		return (-1);
	for (node = sh_data->hst; node; node = node->nx)
	{
		_sf_gfw_sq(node->str, gfw);
		_putgfw('\n', gfw);
	}
	_putgfw(_F_BUF, gfw);
	close(gfw);
	return (1);
}


/**
 * _start_hst_man - wwwwwwwwww
 * @sh_data: stuff
 * @_ll_pl: _ll_plfer
 * @_len_gfw: the hst _len_gfw, _ln_len
 *
 * Return: Always 0
 */
int _start_hst_man(shell_data_ *sh_data, char *_ll_pl, int _len_gfw)
{
	_lst *node = NULL;

	if (sh_data->hst)
		node = sh_data->hst;
	_ll_end_app(&node, _ll_pl, _len_gfw);

	if (!sh_data->hst)
		sh_data->hst = node;
	return (0);
}
