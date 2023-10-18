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
