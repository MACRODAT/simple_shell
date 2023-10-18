#include "shell.h"

/**
 **_sh_nen - wed
 *@s: thdweeewd
 *@b: tewd
 *@n: the amweddwe
 *Return: dwed
 */
char *_sh_nen(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * _realloc - ewdwe
 * @ptr: edwcd
 * @old_size: csdlockds
 * @new_size: The dcsc
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
 * my_free_ - dwe
 * @se: ssw
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
