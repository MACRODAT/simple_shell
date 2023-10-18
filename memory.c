#include "shell.h"

/**
 * fr_db - Free memory allocated for a pointer and set it to NULL.
 *
 * This function checks if the provided pointer 'ptr' is not NULL and if
 * '*ptr' points to allocated memory. If these conditions are met, it frees the
 * memory, sets '*ptr' to NULL, and returns 1.
 * If the conditions are not met, it
 * returns 0.
 *
 * @ptr: A double pointer to the pointer whose memory needs to be freed.
 *
 * Return: 1 if memory is freed and set to NULL, 0 otherwise.
 */
int fr_db(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
