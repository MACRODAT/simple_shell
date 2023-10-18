#include "shell.h"

/**
 * _file_hst_loc - erg
 * @info: ger
 *
 * Return: ger
 */

char *_file_hst_loc(shell_data_ *info)
{
	char *_ll_pl, *dir;

	dir = _getenv(info, "HOME=");
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
 * write_history - ewfwe
 * @info: apr
 *
 * Return: 1
 */
int write_history(shell_data_ *info)
{
	ssize_t fd;
	char *filename = _file_hst_loc(info);
	_lst *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->nx)
	{
		_sf_fd_sq(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(_F_BUF, fd);
	close(fd);
	return (1);
}

/**
 * hstory - reads history from file
 * @info: the parameter struct
 *
 * Return: _ln_len on success, 0 otherwise
 */
int hstory(shell_data_ *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *_ll_pl = NULL, *filename = _file_hst_loc(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	_ll_pl = malloc(sizeof(char) * (fsize + 1));
	if (!_ll_pl)
		return (0);
	rdlen = read(fd, _ll_pl, fsize);
	_ll_pl[fsize] = 0;
	if (rdlen <= 0)
		return (free(_ll_pl), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (_ll_pl[i] == '\n')
		{
			_ll_pl[i] = 0;
			_start_hst_man(info, _ll_pl + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		_start_hst_man(info, _ll_pl + last, linecount++);
	free(_ll_pl);
	info->_ln_len = linecount;
	while (info->_ln_len-- >= SZ_HST)
		delete_node_at_index(&(info->history), 0);
	_hst_org(info);
	return (info->_ln_len);
}

/**
 * _start_hst_man - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @_ll_pl: _ll_plfer
 * @linecount: the history linecount, _ln_len
 *
 * Return: Always 0
 */
int _start_hst_man(shell_data_ *info, char *_ll_pl, int linecount)
{
	_lst *node = NULL;

	if (info->history)
		node = info->history;
	_ll_end_app(&node, _ll_pl, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * _hst_org - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new _ln_len
 */
int _hst_org(shell_data_ *info)
{
	_lst *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->nx;
	}
	return (info->_ln_len = i);
}
