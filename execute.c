#include "shell.h"

/**
 * _execute_command - edj
 * @command: exec
 * @data: data
 *
 * Return: erer
*/
int _execute_command(char *command, shelldata_ *data)
{
	pid_t p;
	int stat;
	/* char *a[] = {command, NULL}; */
	char **tokens = NULL;
	int ind = 0;
	char *new_path;

	UNUSED(command);
	tokens = data->command_tokens;
	if (!tokens)
	{
		_puts_and_flush_e("Could not parse command.\n");
		return (-1);
	}
	new_path = tokens[0];
	if (access(new_path, F_OK) >= 0)
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
			if (access(new_path, F_OK) >= 0)
			{
				goto success;
			}
		}
		return (-123);
	}
success:
	p = fork();
	stat = 0;
	return (follow_execution(tokens, p, stat, new_path));
}

/**
 * follow_execution - edj
 * @tokens: exec
 * @p: data
 * @stat: data
 * @new_path: data
 *
 * Return: erer
*/
int follow_execution(char **tokens, pid_t p, int stat, char *new_path)
{
	tokens[0] = new_path;
	if (p == -1)
	{
		return (-1);
	}
	else if (p == 0)
	{
		execve(new_path, tokens, environ);
		exit(1);
	}
	else
	{
		if (waitpid(p, &stat, 0) > 0)
		{
			if (WIFEXITED(stat) && !WEXITSTATUS(stat))
			{
				return (0);
			}
			else if (WIFEXITED(stat) && WEXITSTATUS(stat))
			{
				return (-1);
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			return (-1);
		}
	}
}
