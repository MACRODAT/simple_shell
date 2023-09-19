#include "shell.h"

/**
 * command - displays command prompt and waits for user
 *
 * Return: result
*/
int command(shelldata_ *data)
{
	char *cd_all = NULL;
	
	size_t len = BUFFER_SIZE_READER;
	int res;

	do
	{
		if (data->interactive == 1)
		{
			_puts("$ ");
			_putchar(SPECIAL_CHAR);
		}
		res = _getline(&cd_all, &len, stdin);
		if (!cd_all || res < 0)
			break;
		if (_process_lines(data, cd_all) != 0)
		{
			/* error processing */
		}
	}
	while (data->interactive);
	return (0);
}

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

	cd_lines = _splitString(cd_all, delimiters2, &cd_lines_len);
	cd = malloc(sizeof(char) * STANDART_BUFFER);
	if (!cd)
	{
		_puts_and_flush_e("Error in Memory.");
		free_info(data, 0);
		return (-1);
	}
	while(cd_lines && *cd_lines && (_strcpy(cd, *cd_lines)))
	{

		if (!_trim(&cd))
		{
			_puts_and_flush_e("Error Parsing.");
			free_info(data, 0);
			return (-1);
		}
		if (_strlen(cd) == 0){
			cd_lines++;
			continue;
		}
		data->cd = _strdup(cd);
		data->command_tokens = _splitString(cd, delimiters, &data->tokensize);
		if (_exec_builtin(data->command_tokens[0], data) != -404)
		{
			/* POSTEXECUTE */
		}
		else if ((commandResult = _execute_command(cd, data)) != 0)	
		{
			_putchar_e('.');
			_putchar_e('/');
			_puts_e(data->filename);
			_puts_and_flush_e(": No such file or directory.\n");
		}

		_putchar(SPECIAL_CHAR);
		free_info(data, 0);
		cd_lines++;
	}
	return (0);
}
