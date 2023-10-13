#include "shell.h"

/**
 * _process_lines - processes cd lines
 * @data: shelldata
*/
int _process_lines(shelldata_ *data, char *cd_all)
{
	char *cd = NULL;
	char **cd_lines = NULL;
	int cd_lines_len = 0;
	char *delimiters = " \t";
	char *delimiters2 = ";";
	int commandResult;
	char *tmp;

	cd_lines = _splitString(cd_all, delimiters2, &cd_lines_len);
	cd = malloc(sizeof(char) * STANDART_BUFFER);
	if (!cd)
	{
		_puts_and_flush_e("Error in Memory.");
		free_info(data, 0);
		if (cd_lines)
			__free_str_str(cd_lines);
		if (cd)
			free(cd);
		cd_lines = 0;
		cd = 0;
		tmp = 0;
		return (-1);
	}
	while(cd_lines && *cd_lines && (_strcpy(cd, *cd_lines)))
	{
		data->commandNumber++;
		if (!_trim(&cd))
		{
			if (!data->interactive)
				return (-20);
			_puts_and_flush_e("Error Parsing.");
			free_info(data, 0);
			if (cd_lines)
				__free_str_str(cd_lines);
			if (cd)
				free(cd);
			if (tmp)
				free(tmp);
			cd_lines = 0;
			cd = 0;
			tmp = 0;
			return (-1);
		}
		if (_strlen(cd) == 0)
		{
			cd_lines++;
			continue;
		}
		data->command_tokens = _splitString(cd, delimiters, &data->tokensize);
		data->cd = _strdup(cd);
		if (_exec_builtin(data->command_tokens[0], data) != -404)
		{
			/* POSTEXECUTE */
		}
		else if ((commandResult = _execute_command(cd, data)) < 0)	
		{
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
				cd_lines = 0;
				cd = 0;
				exit(EXIT_FAILURE);
			}
		}

		_putchar(SPECIAL_CHAR);
		free_info(data, 0);
		cd_lines++;
	}
	if (cd_lines)
		__free_str_str(cd_lines);
	if (cd)
		free(cd);
	cd_lines = 0;
	cd = 0;
	tmp = 0;
	return (0);
}
