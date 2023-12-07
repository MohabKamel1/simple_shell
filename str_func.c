#include "shell.h"

/**
 * _strlength - return length string
 * @s: input
 * Retrun: no. length of string
 */

int _strlength(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcompar - comapre between two strings
 * @s1: input
 * @s2:input
 * Return: negative s1 <s2, positive s1 > s2, 0 s1 == s2
 */

int _strcompar(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * *starts_by - if needle starts by haystack
 * @haystack: input
 * @needle: input
 * Return: address or NULL
 */

char *starts_by(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * *_strconcat - concatenate two strings
 * @dst: input
 * @src: input
 * Return: pointer to dst
 */

char *_strconcat(char *dst, char *src)
{
	char *ret = dst;

	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = *src;
	return (ret);
}
