#include "shell.h"

/**
 * executable - few
 * @sh_data: effwe
 * @path: patfwe
 *
 * Return: 1 idwe
 */
int executable(shell_data_ *sh_data, char *path)
{
	struct stat st;

	(void)sh_data;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * where_is - dew
 * @sh_data: de
 * @_loc_st_2: edw
 * @cmd: ewd
 *
 * Return: Tdwe
 */
char *where_is(shell_data_ *sh_data, char *_loc_st_2, char *cmd)
{
	int i = 0, cur_pso = 0;
	char *loc;

	if (!_loc_st_2)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (executable(sh_data, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!_loc_st_2[i] || _loc_st_2[i] == ':')
		{
			loc = dup_chars(_loc_st_2, cur_pso, i);
			if (!*loc)
				_strcat(loc, cmd);
			else
			{
				_strcat(loc, "/");
				_strcat(loc, cmd);
			}
			if (executable(sh_data, loc))
				return (loc);
			if (!_loc_st_2[i])
				break;
			cur_pso = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * dup_chars - wdc
 * @_loc_st_2: we
 * @start: wed
 * @stop: dwe
 *
 * Return: wed
 */
char *dup_chars(char *_loc_st_2, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (_loc_st_2[i] != ':')
			buf[k++] = _loc_st_2[i];
	buf[k] = 0;
	return (buf);
}
