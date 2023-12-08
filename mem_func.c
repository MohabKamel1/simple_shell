#include "shell.h"

/**
 * *_mmset - memory with constant
 * @s: input
 * @b: input
 * @n: input
 * Return: pointer ti memory
 */

char *_mmset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * vfree - free strings
 * @pp: input
 */

void vfree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _reallocate - block of memory to locate
 * @ptr: input
 * @o_size: input
 * @n_size: input
 * Return: pointer to old block
 */

void *_reallocate(void *ptr, unsigned int o_size, unsigned int n_size)
{
	char *p;

	if (!ptr)
		return (malloc(n_size));
	if (!n_size)
		return (free(ptr), NULL);
	if (n_size == o_size)
		return (ptr);

	p = malloc(n_size);
	if (!p)
		return (NULL);

	o_szie = o_size < n_size ? o_size : n_size;
	while (o_size--)
		p[o_size] = ((char *)ptr)[o_size];
	free(ptr);
	return (p);
}
