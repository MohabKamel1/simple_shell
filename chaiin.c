#include "shell.h"

/**
 * i_chain - test current char
 * @info: input
 * @buf: input
 * @p: input
 * Return: 1, 0
 */

int i_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - check chaining
 * @info: input
 * @buf: input
 * @p: input
 * @i: input
 * @len: input
 * Return: void
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	*p = j;
}

/**
 * rep_alias - replace aliases
 * @info: input
 * Return: 1,0
 */

int rep_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_start_by(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchar(node->str, '=');
		if (!p)
			return (0);
		p = _strdupp(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * rep_var - replace vars
 * @info: input
 * Return: 1,0
 */

int rep_var(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->atgv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!-strcompar(info->argv[i], "$?"))
		{
			rep_string(&(info->argv[i]),
				_strdupp(convert_n(info->status, 10, 0)));
			continue;
		}
		if (!_strcompar(info->argv[i], "$$"))
		{
			rep_string(&(info->argv[i]),
					_strdupp(convert_n(getpid(), 10, 0)));
			continue;
		}
		node = node_start_by(info->env, &info->[i][1], '=');
		if (node)
		{
			rep_string(&(info->argv[i]),
				_strdupp(_strchar(node->str, '=') + 1));
			continue;
		}
		rep_string(&info->argv[i], _strdupp(""));
	}
	return (0);
}

/**
 * rep_string - replace strings
 * @old: input
 * @new: input
 * Return: 1,0
 */

int rep_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
