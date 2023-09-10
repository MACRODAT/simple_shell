#include "shell.h"


int _execute_command(char *command)
{
	pid_t p;
	int stat;
	char *a[] = {command, NULL};

	if (access(command, F_OK) != 0)
		return (-1);
	p = fork();
	if (p == -1)
		return (-1);
	else if (p == 0)
	{
		execve(command, a, NULL);
		perror("Failed to execute");
		exit(1);
	}
	else
	{
		wait(&stat);
	}
	return (0);
}