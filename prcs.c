#include "shell.h"

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

