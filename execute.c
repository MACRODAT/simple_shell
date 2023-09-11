#include "shell.h"


int _execute_command(char *command)
{
	pid_t p;
	int stat;
	char *a[] = {command, NULL};
	char **tokens = NULL;
	char *delimiters = "\n\t\r\a ";
	int token_size = 0;

	tokens = _splitString(command, delimiters, &token_size);
	p = fork();
	if (p == -1)
		return (-1);
	else if (p == 0)
	{		
		if (!tokens)
		{
			//TODO ERR
			return (-1);
		}
		if (access(tokens[0], F_OK) != 0)
			return (-1);
		execvp(tokens[0], tokens);
		perror("Failed to execute");
		exit(1);
	}
	else
	{
		wait(&stat);
	}
	return (0);
}