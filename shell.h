#ifndef SIMPLESHELL
#define SIMPLESHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>


#define BUFFER_SIZE 1024
#define BUFFER_SIZE_READER 200
#define SPECIAL_CHAR -2
#define AZ 100
#define FILE_BUFFER_SIZE 4096
#define STANDART_BUFFER 4096

#define UNUSED(x) (void)(x)

extern char **environ;

/**
 * struct _linkedlist - doubly linked list
 * @i: number
 * @s: string
 * @s2: string
 * @n: next
 * @p: previous
*/
typedef struct _linkedlist
{
	int i;
	char *s;
	char *s2;
	struct _linkedlist *n;
	struct _linkedlist *p;
} _ll;

/**
 * struct shelldata - Structure to hold shell-related data.
 *
 * This structure is used to store various data related to a shell, including
 * command-line arguments, file paths, environment variables, current working
 * directory, and more.
 *
 * @na: The number of arguments passed to the shell.
 * @a: An array of character pointers representing the shell arguments.
 * @filename: The name of the shell's executable.
 * @filename_full: The full path to the shell's executable.
 * @interactive: Flag indicating whether the shell is running in
 * interactive mode.
 * @path_node: A linked list node for storing path-related information.
 * @path_content_str: A string containing path-related information.
 * @env: A linked list node for storing environment variables.
 * @paths: An array of character pointers representing search paths.
 * @paths_len: The number of elements in the 'paths' array.
 * @curdir: The current working directory.
 * @olddir: The previous working directory.
 * @home: The user's home directory.
 * @command_tokens: An array of character pointers representing
 * parsed command tokens.
 * @tokensize: The number of elements in the 'command_tokens' array.
 * @env_size: The number of environment variables.
 * @cd: A character pointer to the 'cd' command string.
 * @commandNumber: The command number (for history tracking).
 */
typedef struct shelldata
{
	int na;
	char **a;
	char *filename;
	char *filename_full;
	int interactive;
	_ll *path_node;
	char *path_content_str;
	_ll *env;
	char **paths;
	int paths_len;
	char *curdir;
	char *olddir;
	char *home;
	char **command_tokens;
	int tokensize;
	int env_size;
	char *cd;
	int commandNumber;
} shelldata_;

/**
 * struct _builtins - fucntions in cmd
 * @name: name of the function
 * @f: fct
 */
typedef struct _builtins
{
	char *name;
	int (*f)(shelldata_ *data);
} _builtin_;

/* strings */
int _strlen(const char *s);
char *_strcpy(char *dst, char *src);
char *_strdup(const char *str);
int _strcmp(char *sone, char *stwo);
char *_strcat(char *dest, char *src);
char *_starts_with(const char *big, const char *small);
char *_trim(char **sp);
char *_strfromint(int n);
int _atoi(char *s);

/* linked lists */
_ll *_ll_init(_ll **list, int n, char *s, char *s2);
_ll *_ll_add_beg(_ll **list, int n, char *s, char *s2);
_ll *_ll_add_end(_ll **list, int n, char *s, char *s2);
size_t _ll_print(const _ll *lst, const char *sep);
_ll *_ll_delete(_ll *s);
_ll *_ll_delete2(_ll *s);
void _ll_free(_ll *s);

/* prg strings */
int _putchar(char c);
void _puts(char *str);
void _puts_e(const char *str);
void _puts_and_flush(char *str);
int _putchar_e(const char c);
void _puts_and_flush_e(const char *str);
size_t _getline(char **lineptr, size_t *n, FILE *stream);
size_t __getline(char **lineptr, size_t *n, FILE *stream);
void _getFileName(char *path, char **file);
char **_splitString(const char *input, char *delimiter, int *tokenCount);
int _separate_key_val(char *s, char **key, char **val);


/* program */
void initData(shelldata_ *data, int na, char **a);
int command(shelldata_ *data);
int _execute_command(char *command, shelldata_ *data);
int _exec_builtin(char *cd, shelldata_ *data);
void free_info(shelldata_ *data, int flag);
int _process_lines(shelldata_ *data, char *cd_all);
int _print_error(const char *c, shelldata_ *data);
void get_sigint(int sig);
int follow_execution(char **tokens, pid_t p, int stat, char *new_path);
void process_command_(shelldata_ *data, int commandResult,
						char *tmp, char **cd_lines, char *cd);
void _free_stuff(char **cd_lines, char *cd, char *tmp);
int check_stuff(char **s, int buf_size);

/* builtins */
int _builtin_print_env(shelldata_ *data);
void free_info(shelldata_ *data, int flag);
int _builtin_exit(shelldata_ *data);
int _builtin_set(shelldata_ *data);
int _builtin_unset(shelldata_ *data);

/* environment */
void _populate_env(shelldata_ *data);
void _print_env(shelldata_ *data);
void _set_env(shelldata_ *data, char *var, char *val);
void _unset_env(shelldata_ *data, char *var);
void _handle_node_env(shelldata_ *data, _ll *node);
void _handle_node_env_del(shelldata_ *data, char *var);

/* fileio */
int _exec_file(shelldata_ *data, char *file);
int _file_exists(char *file);

/* memory */
void __free_str_str(char **s);

#endif
