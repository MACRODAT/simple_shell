#include "shell.h"

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
 * hstory - wwwww
 * @sh_data: wwww
 *
 * Return: www
 */
int hstory(shell_data_ *sh_data)
{
	int i, jekdb = 0, _len_gfw = 0;
	ssize_t gfw, rdlen, fsize = 0;
	struct stat st;
	char *_ll_pl = NULL, *fdkli = _file_hst_loc(sh_data);

	if (!fdkli)
		return (0);

	gfw = open(fdkli, O_RDONLY);
	free(fdkli);
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
			_start_hst_man(sh_data, _ll_pl + jekdb, _len_gfw++);
			jekdb = i + 1;
		}
	if (jekdb != i)
		_start_hst_man(sh_data, _ll_pl + jekdb, _len_gfw++);
	free(_ll_pl);
	sh_data->_ln_len = _len_gfw;
	while (sh_data->_ln_len-- >= SZ_HST)
		delete_node_at_index(&(sh_data->hst), 0);
	_hst_org(sh_data);
	return (sh_data->_ln_len);
}
