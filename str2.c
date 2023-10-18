#include "shell.h"

/**
 **_strncpy - edwed
 *@dest: twedwe
 *@src: tdwed
 *@n: twedwed
 *Return: thdwe
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
			dest[j++] = '\0';
	}
	return (s);
}
