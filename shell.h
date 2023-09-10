#ifndef SIMPLESHELL
#define SIMPLESHELL


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>


#define BUFFER_SIZE 1024
#define BUFFER_SIZE_READER 1024
#define SPECIAL_CHAR -2

/**
 * struct shelldata - shell data information
 * @na: number arg
 * @a: arguments
*/
typedef struct shelldata
{
	int na;
	char **a;
	int interactive;
} shelldata_;

int _putchar(char c);
void _puts(char *str);
char *_getline();

int command(shelldata_ *data);


#endif