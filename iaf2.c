#include "shell.h"

/**
 * _ll_works - wefwef
 * @_data: fwe
 * @bffuer: wef
 * @p: wef
 * @i: fwe
 * @len: lwefth of bffuer
 *
 * Return: Void
 */
void _ll_works(shell_data_ *_data,
	char *bffuer, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (_data->typ_cd_bf == _TWO)
	{
		if (_data->status)
		{
			bffuer[i] = 0;
			j = len;
		}
	}
	if (_data->typ_cd_bf == _ONE)
	{
		if (!_data->status)
		{
			bffuer[i] = 0;
			j = len;
		}
	}

	*p = j;
}
