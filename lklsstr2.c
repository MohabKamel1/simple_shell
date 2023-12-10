#include "shell.h"

/**
 * ls_len - length of link ls
 * @k: input
 * Return: number
 */

size_t ls_len(const list_t *k)
{
	size_t i = 0;

	while (k)
	{
		k = k->next;
		i++;
	}
	return (i);
}

/**
 * ls_strings - array of strings
 * @head: input
 * Return: array
 */

char **ls_strings(list_t *head)
{
	list_t *node = head;
	size_t i = ls_len(head), j;
	char **strs;
	char str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NLL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlength(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcppy(str, node->str);
		strs[i] = str;
	}
	str[i] = NULL;
	return (strs);
}

/**
 * prt_ls - print elements
 * @k: input
 * Return: number
 */

size_t prt_ls(const list_t *k)
{
	size_t i = 0;

	while (k)
	{
		_puts(convert_n(k->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(k->str ? k->str : "(nil)");
		_puts("\n");
		k = k->next;
		i++
	}
	return (i);
}

/**
 * node_start_by - node whose starts
 * @node: input
 * @prefix: input
 * @c: input
 * Return: node or null
 */

list_t *node_start_by(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_by(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_nindex - get index
 * @head: input
 * @node: input
 * Return: index of -1
 */

ssize_t get_nindex(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

