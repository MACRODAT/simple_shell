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
 * _hst_org - wef
 * @sh_data: fwe
 *
 * Return: fwe
 */
int _hst_org(shell_data_ *sh_data)
{
	_lst *node = sh_data->hst;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->nx;
	}
	return (sh_data->_ln_len = i);
}

/**
 * hstory - reads hst from file
 * @sh_data: the parameter struct
 *
 * Return: _ln_len on success, 0 otherwise
 */
int hstory(shell_data_ *sh_data)
{
	int i, last = 0, _len_gfw = 0;
	ssize_t gfw, rdlen, fsize = 0;
	struct stat st;
	char *_ll_pl = NULL, *filename = _file_hst_loc(sh_data);

	if (!filename)
		return (0);

	gfw = open(filename, O_RDONLY);
	free(filename);
	if (gfw == -1)
		return (0);
	if (!fstat(gfw, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	_ll_pl = malloc(sizeof(char) * (fsize + 1));
	if (!_ll_pl)
		return (0);
	rdlen = read(gfw, _ll_pl, fsize);
	_ll_pl[fsize] = 0;
	if (rdlen <= 0)
		return (free(_ll_pl), 0);
	close(gfw);
	for (i = 0; i < fsize; i++)
		if (_ll_pl[i] == '\n')
		{
			_ll_pl[i] = 0;
			_start_hst_man(sh_data, _ll_pl + last, _len_gfw++);
			last = i + 1;
		}
	if (last != i)
		_start_hst_man(sh_data, _ll_pl + last, _len_gfw++);
	free(_ll_pl);
	sh_data->_ln_len = _len_gfw;
	while (sh_data->_ln_len-- >= SZ_HST)
		delete_node_at_index(&(sh_data->hst), 0);
	_hst_org(sh_data);
	return (sh_data->_ln_len);
}

/**
 * _start_hst_man - adds entry to a hst linked list
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
