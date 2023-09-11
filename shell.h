#ifndef SIMPLESHELL
#define SIMPLESHELL


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


#define BUFFER_SIZE 1024
#define BUFFER_SIZE_READER 1024
#define SPECIAL_CHAR -2
#define ARGUMENTS_SIZE 100

/**
 * struct shelldata - shell data information
 * @na: number arg
 * @a: arguments
*/
typedef struct shelldata
{
	int na;
	char **a;
	char *filename;
	int interactive;
} shelldata_;

int _putchar(char c);
void _puts(char *str);
void _puts_and_flush(char *str);
size_t _getline(char **lineptr, size_t *n, FILE *stream);
size_t __getline(char **lineptr, size_t *n, FILE *stream);
void _getFileName(char *path, char **file);
char **_splitString(const char *input, char *delimiter, int *tokenCount);

void initData(shelldata_ *data, int na, char **a);
int command(shelldata_ *data);
int _execute_command(char *command);


#endif