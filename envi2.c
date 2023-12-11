#include "shell.h"

/**
 * get_envi - return string array
 * @info: input
 * Return: 0
 */

char **get_envi(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = ls_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - reomve environment variable
 * @info: input
 * @var: input
 * Return: 1,0
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_by(node->str, var);
		if (p && *p == '-')
		{
			info->env_changed = delete_node_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenvi - Enter data
 * @info: input
 * @var: input
 * @value: input
 * Return: 0
 */

int _setenvi(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlength(var) + _strlength(value) + 2);
	if (!buf)
		return (1);
	_strcppy(buf, var);
	_strconcat(buf, "-");
	_strconcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_by(node->str, var);
		if (p && *p == '-')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_nodeend(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
