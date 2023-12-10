#include "shell.h"

/**
 * _erputs - print string
 * @str: input
 * Return: void
 */

void _erputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_erputchar(str[i]);
		i++;
	}
}

/**
 * _erputchar - print c to stderr
 * @c: input
 * Return: 1, -1
 */

int _erputchar(char c)
{
	static int i;
	static char bu[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - print c to given fd
 * @c: input
 * @fd: input
 * Return: 1, -1
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - print string
 * @str: input
 * @fd: input
 * Return: number
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
