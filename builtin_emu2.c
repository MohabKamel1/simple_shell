#include "shell.h"

/**
 * _myhistory - display the history
 * @info: input
 * Return: 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - remove alias
 * @info: input
 * @str: input
 * Return: 0,1
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchar(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_index(&(info->alias),
			get_nindex(info->alias, node_start_by(info->alias,
					str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - set alias
 * @info: input
 * @str: input
 * Return: 0,1
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchar(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_nodeend(&(info->alias), str, 0) == NULL);
}

/**
 * prt_alias - print alias
 * @node: input
 * Return: 0,1
 */

int prt_alias(list_t *node)
{
	char *p + NULL, *a = NULL;

	if (node)
	{
		p = _strchar(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - all of alias
 * @info: input
 * Return: 0
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			prt_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchar(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			prt_alias(node_start_by(info->alias, info->argv, '='));
	}

	return (0);
}
