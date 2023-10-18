#include "shell.h"

/**
 * is_delim - wddwe
 * @c: ert
 * @delim: ert ter
 * Return: fwger
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * isnterop - ewd
 * @sh_data: dwe
 *
 * Return: dwe
 */
int isnterop(shell_data_ *sh_data)
{
	return (isatty(STDIN_FILENO) && sh_data->readgfw <= 2);
}

/**
 *_isalpha - rfveg
 *@c: Thger
 *Return: ger
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - edwf
 *@s: tfwe
 *Return: fwefw
 */

int _atoi(char *s)
{
	int i, sign = 1, fg = 0, _s_digit;
	unsigned int _digot_org = 0;

	for (i = 0;  s[i] != '\0' && fg != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			fg = 1;
			_digot_org *= 10;
			_digot_org += (s[i] - '0');
		}
		else if (fg == 1)
			fg = 2;
	}

	if (sign == -1)
		_s_digit = -_digot_org;
	else
		_s_digit = _digot_org;

	return (_s_digit);
}
