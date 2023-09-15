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
	p = fork();
	if (p == -1)
		return (-1);
	else if (p == 0)
	{
		if (!tokens)
		{
			//TODO ERR
			// perror("Failed to execute");
			_puts_and_flush_e("Exec error.\n");
			exit(1);
		}
		new_path = tokens[0];
		if ((access_perm = access(new_path, F_OK)) >= 0)
				goto success;
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
		
		// perror("Failed to execute");
		_puts_and_flush_e("Exec error.\n");
		exit(1);
success:
		execvp(tokens[0], tokens);
		free(new_path);
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
