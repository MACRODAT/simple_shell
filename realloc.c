#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * _realloc - Reallocate memory for a pointer with a new size.
 *
 * This function reallocates memory for the provided pointer 'ptr' with the
 * new size specified by 'new_size'. It transfers the existing data to the new
 * memory block and frees the old memory if needed.
 *
 * @ptr: The pointer to be reallocated.
 * @old_size: The size of the existing memory block.
 * @new_size: The desired new size of the memory block.
 *
 * Return: A pointer to the reallocated memory block or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * my_free_ - frees a string of strings
 * @se: string of strings
 */
void my_free_(char **se)
{
	char **a = se;

	if (!se)
		return;
	while (*se)
		free(*se++);
	free(a);
}
