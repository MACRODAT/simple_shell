#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define _READER_SZ 1024
#define _ZER	0
#define _TWO		2
#define _ONE		1
#define _UNS	2
#define _WR_B 1024
#define _LIN 0
#define _THR	3
#define _LOW	1

#define _F_BUF -1
#define FILE_HST	".history"
#define SZ_HST	4096

extern char **environ;


/**
 * struct _lst - singly linked list
 * @num: the number field
 * @str: a string
 * @nx: points to the nx node
 */
typedef struct _lst
{
	int num;
	char *str;
	struct _lst *nx;
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
 * @_ln_cnt: The current line number in the shell input.
 * @_fla_lns: A flag to indicate whether line counting is enabled.
 * @history: A linked list for command history.
 * @alias: A linked list for command aliases.
 * @env_changed: A flag to indicate changes in the environment.
 * @cmd_buf: Pointer to the command chain buffer for memory management.
 * @environ: An array of environment variables.
 * @env: A linked list for environment variables.
 * @_ln_len: The command history count.
 * @typ_cd_bf: The command type (CMD_type: ||, &&, ;).
 * @readfd: The read file descriptor.
 * @status: The exit status of the last executed command.
 */
typedef struct pswo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int _ln_cnt;
	int err_num;
	int _fla_lns;
	char *fname;
	_lst *env;
	_lst *history;
	_lst *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int typ_cd_bf; /* CMD_type ||, &&, ; */
	int readfd;
	int _ln_len;
} shell_data_;

#define INFO_INIT \
{NULL, NULL, NULL, \
0, 0, 0, 0, NULL, NULL, NULL, \
NULL, NULL, \
0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - builtins
 *@type: cd
 *@func: fct
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
char **strtow(char *, char *);
void _puts(char *);
int _putchar(char);
char *_strdup(const char *);
char *_strncpy(char *, char *, int);
char *convert_number(long int, int, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
int _built_help(shell_data_ *);

char *_memset(char *, char, unsigned int);
void my_free_(char **);
void *_realloc(void *, unsigned int, unsigned int);

int fr_db(void **);

int interactive(shell_data_ *);
int is_delim(char, char *);
void _comm_rem(char *);
int _isalpha(int);
void print_error(shell_data_ *, char *);
int _erratoi(char *);
int _built_hist(shell_data_ *);
int _exit_shell(shell_data_ *);
int print_d(int, int);
int _atoi(char *);


int _built_cd(shell_data_ *);
int _built_alias(shell_data_ *);

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
char *_file_hst_loc(shell_data_ *info);
int write_history(shell_data_ *info);
int hstory(shell_data_ *info);
int _start_hst_man(shell_data_ *info, char *buf, int linecount);
int _hst_org(shell_data_ *info);
_lst *add_node(_lst **, const char *, int);
_lst *_ll_end_app(_lst **, const char *, int);
size_t print_list_str(const _lst *);
int delete_node_at_index(_lst **, unsigned int);
void free_list(_lst **);

size_t list_len(const _lst *);
char **_lsto_strings(_lst *);
size_t print_list(const _lst *);
_lst *_stat_with_lst(_lst *, char *, char);
ssize_t get_node_index(_lst *, _lst *);

int chain_fd(shell_data_ *, char *, size_t *);
void _ll_works(shell_data_ *, char *, size_t *, size_t, size_t);
int alias_rep(shell_data_ *);
int _ll_sub(shell_data_ *);
int _str_abn(char **, char *);

#endif
