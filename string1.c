#include "shell.h"

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
 * _strdup - str dupo
 * @str: dyok
 *
 * Return: ptr
 */
char *_strdup(const char *str)
{
	int _len_ = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		_len_++;
	ret = malloc(sizeof(char) * (_len_ + 1));
	if (!ret)
		return (NULL);
	for (_len_++; _len_--;)
		ret[_len_] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@_s: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *_s)
{
	int i = 0;

	if (!_s)
		return;
	while (_s[i] != '\0')
		_putchar(_s[i++]);
}

/**
 **_strncat - ckncmld
 *@dest: ger
 *@src: reg
 *@n: jerty
 *Return: efw
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
