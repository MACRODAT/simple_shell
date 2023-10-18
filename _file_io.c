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
	int res = 0, ptr = 0, _len = FILE_BUFFER_SIZE, i = 0;
	char *b;
	char c = 0, del = '\n';
	char **lines;

	if (_open_file(data, &ptr, file) != 0)
		return (-1);
	b = malloc(sizeof(char) * _len);
	if (!b)
		return (-1);
	while ((res = read(ptr, &c, 1)) > 0)
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
	lines = _splitString(b, &del, &res);
	if (!lines)
	{
		free(b);
		return (-1);
	}
	i = 0;
	while (i < res)
		_process_lines(data, lines[i++]);
	close(ptr);
	free(b), __free_str_str(lines);
	return (i);
}
/**
 * _open_file - Open a file for reading and set the file descriptor.
 *
 * This function attempts to open a file specified by the 'file' parameter for
 * reading and sets the file descriptor in the 'ptr' variable. If the file
 * opening fails, it handles specific error cases, prints error messages, and
 * exits with appropriate exit codes.
 *
 * @data: Pointer to the shelldata structure holding shell-related data.
 * @ptr: Pointer to the integer where the file descriptor will be stored.
 * @file: The path to the file to be opened.
 *
 * Return: On success, returns EXIT_SUCCESS (0); on failure, returns EXIT_FAILURE.
 */
int _open_file(shelldata_ *data, int *ptr, char *file)
{
	*ptr = open(file, O_RDONLY);
	if (*ptr < 0)
	{
		if (errno == EACCES)
			exit(126);
		if (errno == ENOENT)
		{
			_puts_e(data->filename);
			_puts_e(": 0: Can't open ");
			_puts_e(file);
			_puts_and_flush_e("\n");
			exit(127);
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}