#include "shell.h"

/**
 * _file_exists - iof
 * @file: file handle
 *
 * Return: 1 if exist
 */
int _file_exists(char *file)
{
	if (access(file, F_OK) >= 0)
		return (1);
	return (0);
}

/**
 * _exec_file - executes a files
 * @data: data
 * @file: ptr to file
 *
 * Return: operation result
*/
int _exec_file(shelldata_ *data, char *file)
{
	int res = 0;
	int ptr = 0, _len = FILE_BUFFER_SIZE;
	char *b;
	char c = 0;
	char **lines;
	char del = '\n';
	int i = 0;

	ptr = open(file, O_RDONLY);
	if (ptr < 0)
		return (-1);
	b = malloc(sizeof(char) * _len);
	if (!b)
		return (-1);

	while( (res = read(ptr, &c, 1)) > 0)
	{
		b[i++] = c;
		if (i >= _len)
		{
			_len *= 2;
			b = (char *)realloc(b, sizeof(char) * _len);
			if (!b)
				return (-1);
		}
	}
	if (res < 0)
	{
		free(b);
		return (-1);
	}
	/* #TODO HANDLE LARGER FILES */
	lines = _splitString(b, &del, &res);
	if (!lines)
	{
		free(b);
		return (-1);
	}
	i = 0;
	while (i < res)
	{
		_process_lines(data, lines[i]);
		i++;
	}
	close(ptr);
	free(b);
	__free_str_str(lines);
	return (i);
}
