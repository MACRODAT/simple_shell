#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define _READER_SZ 1024
#define _ZER	0
#define _F_BUF -1
#define _TWO		2
#define _ONE		1
#define _UNS	2
#define _WR_B 1024
#define _THR	3
#define _LOW	1
#define _LIN 0

#define FILE_HST	".history"
#define SZ_HST	4096

extern char **environ;


/**
 * struct _lst - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct _lst
{
	int num;
	char *str;
	struct _lst *next;
} _lst;

/**
 * struct pswo - Structure to hold shell-related information.
 *
 * This structure is used to store various information
 * and data related to a shell.
 *
 * @arg: The current command argument.
 * @path: The PATH variable.
 * @argv: An array of command arguments.
 * @argc: The number of command arguments.
 * @err_num: The error number.
 * @fname: The file name.
 * @line_count: The current line number in the shell input.
 * @linecount_flag: A flag to indicate whether line counting is enabled.
 * @history: A linked list for command history.
 * @alias: A linked list for command aliases.
 * @env_changed: A flag to indicate changes in the environment.
 * @cmd_buf: Pointer to the command chain buffer for memory management.
 * @environ: An array of environment variables.
 * @env: A linked list for environment variables.
 * @histcount: The command history count.
 * @cmd_buf_type: The command type (CMD_type: ||, &&, ;).
 * @readfd: The read file descriptor.
 * @status: The exit status of the last executed command.
 */
typedef struct pswo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	_lst *env;
	_lst *history;
	_lst *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} shell_data_;

#define INFO_INIT \
{NULL, NULL, NULL, \
0, 0, 0, 0, NULL, NULL, NULL, \
NULL, NULL, \
0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(shell_data_ *);
} builtin_table;


int loop_func(shell_data_ *, char **);
int find_builtin(shell_data_ *);
void find_cmd(shell_data_ *);
void start_execut(shell_data_ *);

int executable(shell_data_ *, char *);
char *dup_chars(char *, int, int);
char *where_is(shell_data_ *, char *, char *);

int looploop_func(char **);

void _err_func(char *);
int _err_func_char(char);
int _putfd(char c, int fd);
int _sf_fd_sq(char *str, int fd);

int _strlen(const char *s);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int fr_db(void **);

int interactive(shell_data_ *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int _erratoi(char *);
void print_error(shell_data_ *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

int _exit_shell(shell_data_ *);
int _mycd(shell_data_ *);
int _myhelp(shell_data_ *);
int _myhistory(shell_data_ *);
int _myalias(shell_data_ *);

ssize_t get_input(shell_data_ *);
int _getline(shell_data_ *, char **, size_t *);
void sigintHandler(int);

void clear_info(shell_data_ *);
void set_info(shell_data_ *, char **);
void free_info(shell_data_ *, int);
char *_getenv(shell_data_ *, const char *);
int _myenv(shell_data_ *);
int _mysetenv(shell_data_ *);
int _myunsetenv(shell_data_ *);
int fill_env(shell_data_ *);
char **get_environ(shell_data_ *);
int _unsetenv(shell_data_ *, char *);
int _setenv(shell_data_ *, char *, char *);
char *get_history_file(shell_data_ *info);
int write_history(shell_data_ *info);
int hstory(shell_data_ *info);
int build_history_list(shell_data_ *info, char *buf, int linecount);
int renumber_history(shell_data_ *info);
_lst *add_node(_lst **, const char *, int);
_lst *add_node_end(_lst **, const char *, int);
size_t print_list_str(const _lst *);
int delete_node_at_index(_lst **, unsigned int);
void free_list(_lst **);

size_t list_len(const _lst *);
char **_lsto_strings(_lst *);
size_t print_list(const _lst *);
_lst *node_starts_with(_lst *, char *, char);
ssize_t get_node_index(_lst *, _lst *);

int is_chain(shell_data_ *, char *, size_t *);
void check_chain(shell_data_ *, char *, size_t *, size_t, size_t);
int replace_alias(shell_data_ *);
int replace_vars(shell_data_ *);
int replace_string(char **, char *);

#endif
