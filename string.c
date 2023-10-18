#include "shell.h"

/**
 * _strlen - _len
 * @s: str
 *
 * Return: int
 */
int _strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}


/**
 * _strcmp - comparison
 * @sone: s1
 * @stwo: s2
 *
 * Return: 0 or number
 */
int _strcmp(char *sone, char *stwo)
{
	if (!sone || !stwo)
		return (-1);
	while (*sone && *stwo)
	{
		if (*sone != *stwo)
			return (*sone - *stwo);
		sone++;
		stwo++;
	}
	if (*sone == *stwo)
		return (0);
	else
		return (*sone < *stwo ? -1 : 1);
}


/**
 * starts_with - small in big
 * @big: search
 * @small: fnd
 *
 * Return: ptr or null
 */
char *starts_with(const char *big, const char *small)
{
	int i = 0;

	while (small[i])
	{
		if (small[i] != big[i])
			return (NULL);
		i++;
	}
	return ((char *)(big + i));
}

/**
 * _strcat - concatenates two strings
 * @dsti: the dstiination arr_stor
 * @src: the source arr_stor
 *
 * Return: pointer to dstiination arr_stor
 */
char *_strcat(char *dsti, char *src)
{
	char *fin = dsti;

	while (*dsti)
		dsti++;
	while (*src)
		*dsti++ = *src++;
	*dsti = *src;
	return (fin);
}
