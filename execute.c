#include "shell.h"


int _execute_command(char *command, shelldata_ *data)
{
	pid_t p;
	int stat;
	char *a[] = {command, NULL};
	char **tokens = NULL;
	char *delimiters = "\n\t\r\a ";
	int token_size = 0, ind = 0;
	char *new_path;
	int access_perm = -1;

	tokens = _splitString(command, delimiters, &token_size);
	if (!tokens)
	{
		//TODO ERR
		// perror("Failed to execute");
		_puts_and_flush_e("Could not parse command.\n");
		return (-1);
	}
	new_path = tokens[0];

	if ((access_perm = access(new_path, F_OK)) >= 0)
	{

	}
	else
	{
		new_path = malloc(sizeof(char) * STANDART_BUFFER);
		while (data->paths && data->paths[ind])
		{
			_strcpy(new_path, data->paths[ind++]);
			new_path = _strcat(new_path, "/");
			new_path = _strcat(new_path, tokens[0]);
			if ((access_perm = access(new_path, F_OK)) >= 0)
			{
				goto success;
			}
		}
		free(new_path);
		return (-1);
	}
success:
	if (new_path)
		free(new_path);
	p = fork();
	if (p == -1)
		return (-1);
	else if (p == 0)
	{
		execvp(tokens[0], tokens);
		// perror("Failed to execute");
		_puts_and_flush_e("Exec error.\n");
		exit(1);
	}
	else
	{
		wait(&stat);
	}
	return (0);
}
