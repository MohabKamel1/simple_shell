#include "shell.h"

/**
 * hfree - pointer and NULL
 * @ptr: input
 * Return: 1,0
 */

int hfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
