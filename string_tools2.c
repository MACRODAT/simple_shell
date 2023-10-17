#include "shell.h"

/**
 * _strcat - concat
 * @dest: destination
 * @src: source
 *
 * Return: pointer to destination
 */
char *_strcat(char *dest, char *src)
{
	char *sav = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (sav);
}

/**
 * _starts_with - small in big
 * @big: search
 * @small: fnd
 *
 * Return: ptr or null
 */
char *_starts_with(const char *big, const char *small)
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
 * _trim - trims
 * @sp: str
 *
 * Return: ptr or null
 */
char *_trim(char **sp)
{
	char *new_str = NULL, *s = *sp;
	int len = 0, i = 0, j = 0;
	int last_space = -1;

	if (!s)
		return (NULL);
	while (s[len])
		len++;
	new_str = malloc(sizeof(char) * (len));
	if (!new_str)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r')
		i++;
	while (s[i])
	{
		new_str[j] = s[i];
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\r')
		{
			if (last_space < 0)
				last_space = j;
		}
		else if (s[i] == '#')
		{
			if (last_space < 0)
				last_space = j;
			break;
		}
		else
			last_space = -1;
		i++;
		j++;
	}
	if (last_space > 0)
		new_str[last_space] = 0;
	else
		new_str[j] = 0;
	*sp = new_str;
	return (s);
}

/**
 * _strfromint - concat
 * @n: number
 *
 * Return: pointer to destination
 */
char *_strfromint(int n)
{
	char *sav;
	int i = 0;

	sav = malloc(sizeof(char) * 1000);
	while (n)
	{
		sav[i] = '0' + (n % 10);
		n /= 10;
		i++;
	}
	sav[i] = 0;
	return (sav);
}

/**
 * _atoi - str to int
 * @s: string
 *
 * Return: int
 */
int _atoi(char *s)
{
	int res = 0, i = 0;

	for (i = 0; s[i] != '\0'; ++i)
		res = res * 10 + s[i] - '0';

	return (res);
}
