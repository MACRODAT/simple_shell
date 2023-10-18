#include "shell.h"

/**
 * executable - determines if a file is an executable command
 * @sh_data: the sh_data struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
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
 * dup_chars - Duplicate a range of characters from a string.
 * @pathstr: The source string.
 * @start: The starting index.
 * @stop: The stopping index.
 *
 * Return: A pointer to a new buffer containing the duplicated characters.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * where_is - Find a command in the PATH string.
 * @sh_data: The sh_data struct.
 * @pathstr: The PATH string.
 * @cmd: The command to find.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
char *where_is(shell_data_ *sh_data, char *pathstr, char *cmd)
{
	int i = 0, cur_pso = 0;
	char *loc;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (executable(sh_data, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			loc = dup_chars(pathstr, cur_pso, i);
			if (!*loc)
				_strcat(loc, cmd);
			else
			{
				_strcat(loc, "/");
				_strcat(loc, cmd);
			}
			if (executable(sh_data, loc))
				return (loc);
			if (!pathstr[i])
				break;
			cur_pso = i;
		}
		i++;
	}
	return (NULL);
}
