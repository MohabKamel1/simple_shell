#include "shell.h"

/**
 * *_strncppy - copy strings
 * @dst: input
 * @src: input
 * @n: input
 * Return: concat. strings
 */

char *_strncppy(char *dst, char *src, int n)
{
	int i, j;
	char *s = dst;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dst[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * *_strnconcat - concat. two strings
 * @dst: input
 * @src: input
 * @n: input
 * Return: concat. strings
 */

char *_stnrconcat(char *dst, char *src, int n)
{
	int i, j;
	char *s = dst;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dst[i] = '\0';
	return (s);
}

/**
 * *_strchar - locate a charaters
 * @s: input
 * @c: input
 * Return: s
 */

char *_strchar(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
