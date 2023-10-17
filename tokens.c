#include "shell.h"

/**
 * _splitString - Function to split a string into
 * multiple tokens based on a delimiter
 * @input: in
 * @delimiter: del
 * @tokenCount: ma
 *
 * Return: arr
*/
char **_splitString(const char *input, char *delimiter, int *tokenCount)
{
	char **s = NULL, **_s_tmp = NULL;
	int i = 0, j = 0, last_ind = 0, tok_count = 0, buf_size = AZ, delimited = 0;

	while (input[i++])
	{
		j = 0, delimited = 0;
		while (delimiter[j++])
		{
			if (input[i - 1] == delimiter[j - 1])
			{
				delimited = 1, s[tok_count][last_ind] = 0, last_ind = 0, tok_count++;
				s[tok_count] = malloc(sizeof(char) * BUFFER_SIZE_READER);
				if (!s[tok_count])
				{
					_puts_and_flush_e("error"), free(_s_tmp), free(s);
					return (NULL);
				}
				if (tok_count >= buf_size - 1)
				{
					buf_size *= 2, _s_tmp = (char **)realloc(s, sizeof(char *) * buf_size);
					if (!_s_tmp)
					{
						_puts_and_flush_e("error"), free(s), free(_s_tmp);
						return (NULL);
					}
					s = _s_tmp;
				}
			}
		}
		if (delimited == 0)
			s[tok_count][last_ind++] = input[i - 1];
	}
	s[tok_count][last_ind] = 0, s[tok_count + 1] = 0, *tokenCount = tok_count + 1;
	free(_s_tmp);
	return (s);
}

/**
 * check_stuff - Check and initialize a character array pointer array.
 *
 * This function allocates memory for an array of character pointers and an
 * additional character array. If memory allocation fails, it prints an error
 * message and returns NULL.
 *
 * @s: Double pointer to an array of character pointers.
 * @buf_size: The size of the character pointer array.
 *
 * Return: If successful, returns 0; otherwise, returns -1.
 */
int check_stuff(char **s, int buf_size)
{
	s = (char **)malloc(sizeof(char *) * buf_size);
	if (!s)
	{
		_puts_and_flush_e("error"), free(s);
		return (NULL);
	}
	s[0] = (char *)malloc(sizeof(char) * BUFFER_SIZE_READER);
	if (!s[0])
	{
		_puts_and_flush_e("error"), free(s);
		return (NULL);
	}
}
