#include "shell.h"


int _execute_command(char *command, shelldata_ *data)
{
	pid_t p;
	int stat;
	/* char *a[] = {command, NULL}; */
	char **tokens = NULL;
	int ind = 0;
	char *new_path;
	int access_perm = -1;

	UNUSED(command);
	tokens = data->command_tokens;
	if (!tokens)
	{
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
		return (-123);
	}
success:
	tokens[0] = new_path;
	p = fork();
	if (p == -1)
	{
		return (-1);
	}
	else if (p == 0)
	{
		/* execvp(tokens[0], tokens); */
		execve(new_path, tokens, environ);
		/* _puts_and_flush_e("Exec error.\n"); */
		exit(1);
	}
	else
	{
		if (waitpid(p, &stat, 0) > 0)
		{
			if (WIFEXITED(stat) && !WEXITSTATUS(stat))
			{
				/* all fine */
				return (0);
			}
			else if (WIFEXITED(stat) && WEXITSTATUS(stat))
			{
				/* if (WEXITSTATUS(stat) == 127)
					_puts_and_flush_e("Execution problem !\n");
				else
					_puts_and_flush_e("Return status non-zero.\n"); */
				return (-1);
			}
			else
			{
				/* _puts_and_flush_e("Program termination abnormal.\n"); */
				return (-1);
			}
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}
