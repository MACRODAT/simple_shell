#include "shell.h"

/**
 * _process_lines - processes cd lines
 * @data: shelldata
 * @cd_all: shelldata
 * Return: shelldata
*/
int _process_lines(shelldata_ *data, char *cd_all)
{
	int commandResult, cd_lines_len = 0;
	char *del = " \t", *del2 = ";", *tmp = 0, *cd = NULL, **cd_lines = NULL;

	cd_lines = _splitString(cd_all, del2, &cd_lines_len);
	cd = malloc(sizeof(char) * STANDART_BUFFER);
	if (!cd)
	{
		_puts_and_flush_e("Error in Memory.");
		free_info(data, 0), _free_stuff(cd_lines, cd, tmp);
		return (-1);
	}
	while (cd_lines && *cd_lines && (_strcpy(cd, *cd_lines)))
	{
		data->commandNumber++;
		if (!_trim(&cd))
		{
			if (!data->interactive)
				return (-20);
			_puts_and_flush_e("Error Parsing.");
			free_info(data, 0), _free_stuff(cd_lines, cd, tmp);
			return (-1);
		}
		if (_strlen(cd) == 0 && cd_lines++)
			continue;
		data->command_tokens = _splitString(cd, del, &data->tokensize);
		data->cd = _strdup(cd);
		if (_exec_builtin(data->command_tokens[0], data) != -404)
		{
		}
		else
		{
			commandResult = _execute_command(cd, data);
			if (commandResult < 0)
				process_command_(data, commandResult, tmp, cd_lines, cd);
		}

		_putchar(SPECIAL_CHAR), free_info(data, 0), cd_lines++;
	}
	_free_stuff(cd_lines, cd, tmp);
	return (0);
}

/**
 * _free_stuff - Frees memory allocated for various pointers.
 *
 * This function frees memory allocated for the provided character arrays and
 * sets the pointers to NULL to prevent dangling references.
 *
 * @cd_lines: Double pointer to an array of strings.
 * @cd: Pointer to a character array.
 * @tmp: Pointer to a character array.
 */
void _free_stuff(char **cd_lines, char *cd, char *tmp)
{
	if (cd_lines)
		__free_str_str(cd_lines);
	if (cd)
		free(cd);
	if (tmp)
		free(tmp);
	cd_lines = 0, cd = 0, tmp = 0;
}

/**
 * process_command_ - geue
 * @data: deh
 * @commandResult: deh
 * @tmp: deh
 * @cd_lines: deh
 * @cd: deh
*/
void process_command_(shelldata_ *data, int commandResult, char *tmp,
							char **cd_lines, char *cd)
{
	tmp = 0;
	if (commandResult == -123)
	{
		/* REMOVED INTERACTIVE CHECK */
		_puts_e(data->filename_full);
		_putchar_e(':');
		_putchar_e(' ');
		tmp = _strfromint(data->commandNumber);
		_puts_and_flush_e(tmp);
		_putchar_e(':');
		_putchar_e(' ');
		_puts_and_flush_e(cd);
		_puts_and_flush_e(": not found\n");
		free(tmp);
		tmp = 0;
	}
	if (data->interactive == 0)
	{
		free_info(data, 1);
		if (cd_lines)
			__free_str_str(cd_lines);
		if (cd)
			free(cd);
		cd_lines = 0, cd = 0;
		exit(EXIT_FAILURE);
	}
}
