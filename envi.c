#include "shell.h"

/**
 * _myenvi - print the envi
 * @info: input
 * Return: 0
 */

int _myenvi(info_t *info)
{
	prt_ls_str(info->env);
	return (0);
}

/**
 * _getenvi - get value
 * @info: input
 * @name: input
 * Return: number
 */

char *_getenvi(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_by(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenvi - Enter data
 * @info: input
 * Return: 0
 */

int _mysetenvi(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of argm\n");
		return (1);
	}
	if (_setenvi(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenvi - Remove envi
 * @info: input
 * Return: 0
 */

int _myunsetenvi(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few argm.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenvi(info, info->argv[i]);

	return (0);
}

/**
 * populate_envi_ls - populates env linked ls
 * @info: input
 * Return: 0
 */

int populate_envi_ls(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_nodeend(&node, environ[i], 0);
	info->env = node;
	return (0);
}
	_
