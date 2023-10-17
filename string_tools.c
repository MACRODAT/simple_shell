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
 * _strcpy - copier
 * @dst: dest
 * @src: src
 *
 * Return: ptr to dest
 */
char *_strcpy(char *dst, char *src)
{
	int i = 0;

	if (!src)
		return (NULL);
	if (src == 0 || dst == src)
		return (dst);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/**
 * _strdup - dup
 * @str: str
 *
 * Return: ptr to dup
 */
char *_strdup(const char *str)
{
	int _len = 0, i = 0;
	char *dst = 0;

	if (str == NULL)
		return (0);
	_len = _strlen(str);
	dst = malloc((_len + 2) * sizeof(char));
	if (!dst)
		return (NULL);
	for (i = 0; i < _len; i++)
		dst[i] = str[i];
	dst[_len + 1] = 0;
	return (dst);
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
