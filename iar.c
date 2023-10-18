#include "shell.h"

/**
 * alias_rep - repdew
 * @_data: we
 *
 * Return: d dweded
 */
int alias_rep(shell_data_ *_data)
{
	int i;
	_lst *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = _stat_with_lst(_data->alias, _data->poss[0], '=');
		if (!node)
			return (0);
		free(_data->poss[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		_data->poss[0] = p;
	}
	return (1);
}

/**
 * _ll_sub - wefwe
 * @_data: fwe
 *
 * Return: fewe
 */
int _ll_sub(shell_data_ *_data)
{
	int i = 0;
	_lst *node;

	for (i = 0; _data->poss[i]; i++)
	{
		if (_data->poss[i][0] != '$' || !_data->poss[i][1])
			continue;

		if (!_strcmp(_data->poss[i], "$?"))
		{
			_str_abn(&(_data->poss[i]),
				_strdup(_numb_base_10(_data->status, 10, 0)));
			continue;
		}
		if (!_strcmp(_data->poss[i], "$$"))
		{
			_str_abn(&(_data->poss[i]),
				_strdup(_numb_base_10(getpid(), 10, 0)));
			continue;
		}
		node = _stat_with_lst(_data->env, &_data->poss[i][1], '=');
		if (node)
		{
			_str_abn(&(_data->poss[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		_str_abn(&_data->poss[i], _strdup(""));

	}
	return (0);
}

/**
 * _str_abn - replwewef
 * @old: aefw
 * @new: nefw
 *
 * Return: ewf
 */
int _str_abn(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

/**
 * chain_gfw - fwe
 * @_data: fwe
 * @bffuer: herqhrh
 * @p: herqh
 *
 * Return: wef
 */
int chain_gfw(shell_data_ *_data, char *bffuer, size_t *p)
{
	size_t j = *p;

	if (bffuer[j] == '|' && bffuer[j + 1] == '|')
	{
		bffuer[j++] = 0;
		_data->typ_cd_bf = _ONE;
	}
	else if (bffuer[j] == '&' && bffuer[j + 1] == '&')
	{
		bffuer[j++] = 0;
		_data->typ_cd_bf = _TWO;
	}
	else if (bffuer[j] == ';')
	{
		bffuer[j] = 0;
		_data->typ_cd_bf = _THR;
	}
	else
		return (0);
	*p = j;
	return (1);
}
