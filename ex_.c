#include "shell.h"

/**
 **_strchr - str loc
 *@s: s
 *@c: s
 *Return: djikope
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
