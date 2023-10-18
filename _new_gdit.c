#include "shell.h"

/**
 * print_d - ffwerf
 * @input: thfsd ssdffsdf
 * @gfw: thsfd
 *
 * Return: numsdf
 */
int print_d(int input, int gfw)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, low_fd_nw;

	if (gfw == STDERR_FILENO)
		__putchar = _err_func_char;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	low_fd_nw = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + low_fd_nw / i);
			count++;
		}
		low_fd_nw %= i;
	}
	__putchar('0' + low_fd_nw);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & _UNS) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & _LOW ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}